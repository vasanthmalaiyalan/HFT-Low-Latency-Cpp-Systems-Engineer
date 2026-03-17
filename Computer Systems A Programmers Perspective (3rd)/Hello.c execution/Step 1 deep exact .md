சரி 🔥 — இப்ப நீ கேட்டது **full deep execution (Step 1)**
👉 *keyboard press இருந்து → file save → RAM inode update வரை*
👉 **exact, clean, no confusion, full pipeline** 👇

---

# 🚀 STEP 1 — FULL EXECUTION (END-TO-END)

---

# 🔹 PART 1 — Keyboard → Kernel (hardware → kernel space)

```text
Keyboard press
↓
Keyboard controller (hardware)
↓
Scan code generate
   (e.g., Shift + 3 → make/break codes)
↓
CPU interrupt (IRQ)
↓
Kernel interrupt handler
↓
Keyboard driver (kernel space)
↓
Input subsystem
↓
Keycode உருவாகும் (e.g., KEY_3, KEY_LEFTSHIFT)
↓
Keyboard layout mapping
↓
Character உருவாகும் → '#'
↓
Encoding → UTF-8 → 0x23
```

👉 இங்கே வரை:

```text
Kernel Space
----------------
TTY buffer:
0xffff2000 : 0x23
```

---

# 🔹 PART 2 — Kernel → User (read path)

Editor already running (vim / vscode)

```c
read(0, buf, 1);
```

Flow:

```text
User Space (editor)
↓
read() syscall
↓
Kernel (tty_read)
↓
TTY buffer check
↓
data available (0x23)
↓
copy_to_user()
↓
User buffer update
```

👉 Result:

```text
User Space
-----------
buf[0] = 0x23   ('#')
```

---

# 🔹 PART 3 — Editor buffer + Screen

```text
editor internal buffer update
↓
screen draw request
↓
write() syscall (stdout / terminal)
↓
kernel tty driver
↓
terminal emulator
↓
GPU
↓
Screen shows: #
```

👉 முக்கியம்:

```text
👉 read() → data பெற
👉 write() → screen காட்ட
```

---

# 🔹 PART 4 — Save file (write path)

User action:

```text
:w   (vim save)
```

Editor call:

```c
write(fd, buffer, size);
```

Example:

```c
write(3, 0x7ffe9100, 1);
```

---

# 🔹 PART 5 — User → Kernel (write syscall)

```text
User Space
-----------
buf: '#'

↓ write()

Kernel Space
------------
sys_write()
↓
copy_from_user()
↓
kernel buffer = 0x23   ✅
```

👉 முக்கியம்:

```text
copy ஆகுவது → data மட்டும் (#)
copy ஆகாதது → fd, address, size
```

---

# 🔹 PART 6 — VFS layer

```text
vfs_write()
↓
fd → struct file
↓
file → inode
↓
filesystem type கண்டுபிடி (ext4)
```

👉 already known:

```text
inode exists
block mapping exists / இல்லா இருக்கலாம்
```

---

# 🔹 PART 7 — ext4_file_write_iter() (🔥 core)

```text
ext4_file_write_iter()

↓ offset = file->f_pos (e.g., 0)
↓ page கண்டுபிடி (page cache)
↓ inode → block mapping check
↓ (if needed) block allocate
↓ data copy → page cache
↓ mark page dirty
↓ inode (RAM) update
```

---

# 🔹 PART 8 — RAM state

```text
Page Cache (RAM)
----------------
[0] = 0x23   (#)

inode (RAM)
------------
size = 1
mtime updated
```

👉 இங்கே:

```text
dirty = 1   🔥
```

---

# ❗ முக்கிய நிலை

```text
❌ disk-ல் இன்னும் இல்லை
✅ RAM-ல் மட்டும் இருக்கிறது
```

---

# 🔹 PART 9 — Return to user

```c
write() → return 1
```

👉 meaning:

```text
"RAM-ல் எழுதிவிட்டேன்"
```

---

# 🧠 FULL PIPELINE (ONE VIEW)

```text
Keyboard
↓
Kernel (driver + input)
↓
TTY buffer (0x23)
↓
read()
↓
copy_to_user()
↓
Editor buffer
↓
write() (screen)
↓
Display '#'

-------------------------

Save:

write(fd, buf, 1)
↓
sys_write()
↓
copy_from_user()
↓
VFS
↓
ext4_file_write_iter()
↓
page cache (RAM)
↓
inode update (RAM)
↓
dirty = 1
```

---

# 🔑 FINAL ONE-LINE

```text
keyboard → kernel → read → user buffer → write → kernel →
filesystem → RAM page cache → inode update (dirty)
```

---

🔥 இப்ப நீ **complete Step 1 (end-to-end execution)** master பண்ணிட்ட

👉 next stage:

```text
dirty → disk actual write (writeback, block layer, IO scheduler)
```

😈 இது தான் real storage deep dive

---

சொல்லு — next stage போவோமா?


-----

இந்த pipeline-ஐ layer-by-layer deep dive பண்றோம். ஒவ்வொரு step-உம் **exactly என்ன நடக்குது** என்று explain பண்றேன்.

---

# PART 1 — Keyboard → Kernel

## Keyboard press ஆகும்போது என்ன நடக்குது?

Keyboard என்பது ஒரு hardware device. நீ `#` press பண்ணும்போது:

**Step 1 — Scan Code:**
Keyboard-ல் ஒரு microcontroller இருக்கு. அது key matrix scan பண்ணி ஒரு **scan code** generate பண்ணும்.

```
Shift + 3 press
→ make code: 0x2A (Shift), 0x04 (3)
→ release: break code (0x2A | 0x80)
```

**Step 2 — IRQ (Interrupt Request):**
Keyboard controller CPU-க்கு **IRQ1** signal அனுப்பும். CPU இதை receive பண்ணி current execution-ஐ pause பண்ணும்.

```
CPU normal execution
↓
IRQ1 signal வருது
↓
CPU: "interrupt! save current state"
↓
registers → stack-ல் push
↓
IDT (Interrupt Descriptor Table) lookup
↓
keyboard interrupt handler address கண்டுபிடி
↓
handler-க்கு jump
```

**IDT என்னன்னா?**
ஒரு table — interrupt number → handler function address. IRQ1 → `atkbd_interrupt()` function.

**Step 3 — Kernel Keyboard Driver:**

```c
// kernel/drivers/input/keyboard/atkbd.c
atkbd_interrupt()
↓
scan code படி
↓
input_event(dev, EV_KEY, KEY_3, 1)  // key press
input_event(dev, EV_KEY, KEY_LEFTSHIFT, 1)
```

**Step 4 — Input Subsystem:**
Linux input subsystem scan code → keycode-ஆ convert பண்ணும்.

```
scan code 0x04 → KEY_3 (keycode 11)
```

**Step 5 — Keyboard Layout Mapping:**
`KEY_3` + `SHIFT` → character `#` → UTF-8 encoding → `0x23`

```
TTY buffer-ல் write:
address 0xffff2000 : 0x23
```

---

# PART 2 — Kernel TTY → User Space (read path)

## Editor எப்படி character-ஐ பெறுகிறது?

Editor (vim/vscode) already running. அது `read()` syscall-ல் **block** ஆகி காத்திருக்கும்.

```c
// editor process
read(STDIN_FILENO, buf, 1);
// இங்கே process sleep ஆகி இருக்கு — data வரும் வரை
```

**Syscall என்னன்னா?**
User space process kernel-ஐ directly call பண்ண முடியாது — memory protection இருக்கு. `syscall` instruction மட்டும் kernel-க்கு safe entry point.

```
read() call
↓
glibc wrapper
↓
syscall instruction (x86: int 0x80 or syscall opcode)
↓
CPU: user mode → kernel mode switch
↓
sys_read() kernel function
↓
tty_read()
↓
TTY buffer check: data இருக்கா?
↓
YES — 0x23 இருக்கு
↓
copy_to_user(buf, kernel_buf, 1)
↓
CPU: kernel mode → user mode switch
↓
editor-ன் buf[0] = 0x23 ('#')
```

**copy_to_user() ஏன் தேவை?**
Kernel memory → user memory directly copy பண்ண முடியாது. Page table permissions different. `copy_to_user()` ஒரு safe bridge — destination address valid-ஆ இருக்கா என்று check பண்ணும், fault handle பண்ணும்.

---

# PART 3 — Editor Buffer + Screen Display

## Screen-ல் எப்படி `#` தெரியுது?

```
editor: buf[0] = '#' received
↓
editor internal buffer update (e.g., vim's gap buffer)
↓
cursor position update
↓
screen redraw trigger
↓
write(STDOUT_FILENO, "#", 1)  // terminal-க்கு write
↓
sys_write()
↓
tty driver
↓
terminal emulator (e.g., Windows Terminal, GNOME Terminal)
↓
terminal: character render பண்ண GPU command அனுப்பும்
↓
GPU: font glyph lookup → pixels draw
↓
Screen: '#' தெரியும்
```

**முக்கியமான point:**
`read()` → data பெறுவதற்கு.
`write()` → display பண்றதற்கு.
இரண்டும் separate syscalls — separate paths.

---

# PART 4, 5 — File Save: write() Syscall Deep Dive

## `:w` press பண்ணும்போது என்ன நடக்குது?

```c
write(fd, buffer, size);
// fd = 3 (file descriptor, open file-க்கான handle)
// buffer = 0x7ffe9100 (user space address)
// size = 1
```

**fd என்னன்னா?**
Integer மட்டும் — kernel-ல் ஒரு table-ல் index. fd=3 → kernel-ல் `struct file` pointer → இந்த file யாரு, offset என்ன, permissions என்ன எல்லாம் இருக்கு.

```
fd table (per process):
fd 0 → stdin
fd 1 → stdout
fd 2 → stderr
fd 3 → your_file.txt   ← இது
```

**Syscall entry:**
```
write(3, 0x7ffe9100, 1)
↓
syscall instruction
↓
kernel mode
↓
sys_write()
↓
copy_from_user(kernel_buf, 0x7ffe9100, 1)
↓
kernel_buf = 0x23  ✅
```

**copy_from_user() ஏன்?**
User address `0x7ffe9100` valid-ஆ இருக்கா, accessible-ஆ இருக்கா என்று check பண்ணும். Bad address-ஐ kernel-ல் directly dereference பண்ணா kernel crash.

---

# PART 6 — VFS Layer

## VFS என்றால் என்ன?

Virtual File System — Linux-ல் ஒரு abstraction layer.

```
ext4? xfs? btrfs? tmpfs?
↓
எல்லாத்துக்கும் same interface
↓
vfs_write()
```

```
sys_write()
↓
vfs_write()
↓
fd → struct file (kernel object)
↓
struct file → struct inode
↓
inode → filesystem type கண்டுபிடி
↓
ext4 → ext4_file_write_iter() call
```

**inode என்னன்னா?**
File-ஓட metadata store பண்ற kernel structure:

```c
struct inode {
    umode_t     i_mode;      // permissions
    uid_t       i_uid;       // owner
    loff_t      i_size;      // file size
    struct timespec i_mtime; // modified time
    // disk block locations
    // ...
};
```

inode-ல் file name இல்லை — directory-ல் இருக்கு. inode-ல் data இல்லை — disk blocks-ல் இருக்கு.

---

# PART 7 — ext4_file_write_iter() — Core Write

## Data எங்கே போகுது?

```
ext4_file_write_iter()
↓
file offset கண்டுபிடி (f_pos = 0, first write)
↓
Page Cache lookup:
  "இந்த file-ஓட page memory-ல் இருக்கா?"
↓
இல்லன்னா: disk-ல் இருந்து page read (read-modify-write)
இருக்கு: directly use
↓
inode → block mapping check:
  "disk-ல் block allocate ஆச்சா?"
↓
இல்லன்னா: ext4 new block allocate பண்ணும்
↓
data → page cache-ல் copy
↓
page → mark as "dirty"
↓
inode (RAM-ல்) update: size, mtime
```

**Page Cache என்னன்னா?**
RAM-ல் ஒரு cache — disk files-ஓட contents இங்கே இருக்கும். Read/Write எல்லாம் முதல்ல இங்கே நடக்கும், disk-க்கு பிறகு போகும்.

```
Page Cache (RAM)
page[0] of your_file.txt:
offset 0: 0x23  ← '#' இங்கே இருக்கு
```

---

# PART 8 — RAM State After Write

```
Page Cache:
[page 0] = 0x23  dirty=1

inode (RAM):
  i_size = 1
  i_mtime = now
  dirty = 1
```

**dirty flag என்னன்னா?**
"இந்த data disk-ல் இல்லை, RAM-ல் மட்டும் இருக்கு, later disk-க்கு write பண்ணணும்" என்று kernel-க்கு signal.

**இந்த நிலையில்:**
```
✅ RAM-ல் data இருக்கு
❌ Disk-ல் இன்னும் போகல
⚠️ Power cut ஆனா data போச்சு
```

---

# PART 9 — write() Return

```c
return 1;  // 1 byte successfully written (to RAM)
```

Editor-க்கு தெரியும்: write successful. ஆனால் disk guarantee இல்லை. அதனால்தான் `fsync()` என்ற syscall இருக்கு:

```c
fsync(fd);  // "disk-க்கு போகும் வரை wait பண்ணு"
```

---

# Full Pipeline — One View

```
⌨️  Key Press
    ↓
🔌  IRQ1 → CPU interrupt
    ↓
🖥️  Kernel: atkbd_interrupt()
    ↓
📥  Input subsystem → KEY_3 + SHIFT
    ↓
🔤  Layout map → '#' → 0x23
    ↓
📦  TTY buffer: [0xffff2000] = 0x23
    ↓
📖  read() syscall → copy_to_user()
    ↓
✏️  Editor buffer: buf[0] = '#'
    ↓
🖥️  write() → terminal → GPU → Screen shows '#'

──────────── SAVE ────────────

💾  :w → write(fd, buf, 1)
    ↓
⚙️  syscall → sys_write()
    ↓
📋  copy_from_user() → kernel_buf = 0x23
    ↓
🗂️  VFS: fd → struct file → inode
    ↓
📁  ext4_file_write_iter()
    ↓
🧠  Page Cache (RAM): [0] = 0x23, dirty=1
    ↓
📊  inode (RAM): size=1, mtime=now
    ↓
✅  return 1

❌  Disk: இன்னும் போகல → Next: writeback
```

---

## Next Stage — Dirty → Disk:

```
dirty page
↓
pdflush / writeback thread
↓
block layer
↓
IO scheduler (CFQ / deadline / mq-deadline)
↓
device driver
↓
disk controller
↓
actual disk write
↓
dirty flag clear
```

இது தான் **real storage deep dive** — போவோமா?