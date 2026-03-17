சரி Jarvis! இந்த section-ல என்ன நடக்குது னு step-by-step, deep-ஆ பார்க்கலாம். முதல்ல ஒரு diagram பார்க்கலாம், அப்புறம் ஒவ்வொரு stage-யும் விளக்குறேன்.

**`./hello` type பண்ணும்போது என்ன ஆகுது** — 3 major stages இருக்கு:இப்போ ஒவ்வொரு stage-யும் deep-ஆ பார்க்கலாம்.

![alt text](image-1.png)

---

## Stage 1 — Keyboard → Shell → Memory

நீ `./hello` type பண்றப்போ, keyboard-ல press பண்ற ஒவ்வொரு character-உம் ஒரு **electrical signal** ஆகுது. அந்த signal USB controller வழியா **I/O bus**-க்கு போகும். அங்கிருந்து CPU-ல இருக்குற **shell process** அந்த character-ஐ ஒரு **register**-ல படிக்கும் (register = CPU-க்குள்ளே இருக்கற மிகவும் fast memory, just ஒரு variable மாதிரி).

Shell அந்த character-ஐ register-ல மட்டும் வச்சிருக்காது — உடனே **main memory (RAM)**-ல store பண்ணும். ஏன்னா register-ல space மிகவும் குறைவு, temporary-தான். இப்படி ஒவ்வொரு key-உம் RAM-ல சேரும், `./hello` முழுசா ஒரு **string** ஆகி memory-ல உட்கார்ந்திருக்கும்.

---

## Stage 2 — Enter key → DMA → Memory

Enter அடிக்கும்போது shell "command complete" னு தெரிஞ்சுக்கும். இப்போ shell ஒரு sequence of instructions execute பண்ணும் — அந்த instructions `hello` **executable file**-ஐ disk-லிருந்து load பண்ணும்.

இங்கே மிக முக்கியமான concept: **DMA (Direct Memory Access)**.

Normally data-ஐ move பண்ண CPU-யே handle பண்ணணும். But disk → RAM transfer மிகவும் slow + large. CPU-ஐ இதுக்கே block பண்ணா waste. அதனால **DMA controller** னு ஒரு separate hardware இருக்கு. அது CPU-ஐ விட்டுடாம நேரடியா **disk → RAM**-க்கு data copy பண்ணும். CPU இந்த நேரத்துல வேற வேலை பார்க்கலாம்.

DMA transfer முடிஞ்சதும் RAM-ல என்ன இருக்கும்? `hello` program-ரோட **machine code instructions** + `"hello, world\n"` string data — இரண்டும் memory-ல ready.

---

## Stage 3 — CPU executes → Display

இப்போ CPU-க்கு control போகும். **Program Counter (PC)** register `hello` program-ரோட `main()` function-ரோட first instruction-ஐ point பண்ணும். CPU அந்த instruction-ஐ **fetch** பண்ணும், **decode** பண்ணும், **execute** பண்ணும் — இதை **fetch-decode-execute cycle** னு சொல்வாங்க.

`main()` function என்ன பண்ணும்? `printf("hello, world\n")` call பண்ணும். இது இந்த bytes-ஐ RAM-லிருந்து CPU register-க்கு copy பண்ணும், அங்கிருந்து **I/O bus வழியா graphics adapter**-க்கு அனுப்பும். Graphics adapter அந்த bytes-ஐ screen-ல characters ஆக render பண்ணும்.

---

## ஒரு key insight

இந்த whole process-ல data **3 தடவை** copy ஆகுது:
1. Keyboard → RAM (shell படிக்கும்போது)
2. Disk → RAM (DMA load)
3. RAM → CPU registers → Display

இதை CS:APP book **"the memory mountain"** concept-ல explain பண்ணும் — data எவ்வளவு தூரம் travel பண்றதோ, அவ்வளவு slow. அதனால cache hierarchy (L1, L2, L3) exist பண்றது — இதை book-ல Section 1.5 "Caches Matter"-ல அடுத்து cover பண்ணும்!