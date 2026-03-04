
# இந்த book என்ன கற்றுக்கொடுக்கிறது

இந்த book explain செய்யும் core idea:

Program → Compiler → Machine code → CPU → Memory → OS → Hardware

அதாவது:

software  
↓  
hardware

இரண்டுக்கும் உள்ள relationship.

----------

# இந்த book எந்த language பயன்படுத்துகிறது?

Main languages:

C language  
Assembly (x86-64)

Example topics:

C code  
↓  
compiler  
↓  
assembly instructions  
↓  
CPU execution

இதனால் நீங்கள் புரிந்து கொள்வது:

C program actually hardware-ல் எப்படி run ஆகிறது

----------

# Book chapters என்ன cover செய்யும்

### 1️⃣ Machine Representation

Topics:

binary numbers  
bit operations  
integer representation  
floating point

Example:

int  x  =  -1;

CPU-வில் எப்படி represent ஆகிறது.

----------

### 2️⃣ Assembly Language

Topics:

x86 assembly  
registers  
function calls  
stack frames

Example:

movq %rax, %rbx

----------

### 3️⃣ Program Performance

Topics:

CPU cache  
memory hierarchy  
performance optimization

Example:

why some loops faster than others

----------

### 4️⃣ Linking

Topics:

object files  
static linking  
dynamic linking  
shared libraries

Example:

how .o files become executable

----------

### 5️⃣ Virtual Memory

Topics:

virtual memory  
page tables  
address translation

Example:

malloc()

internally என்ன நடக்கிறது.

----------

### 6️⃣ Processes

Topics:

process creation  
fork  
exec  
signals

Example:

fork()

----------

### 7️⃣ Concurrency

Topics:

threads  
race conditions  
synchronization

----------

### 8️⃣ Networking basics

Topics:

client server model  
network sockets  
web servers

----------

# இந்த book why important for HFT / systems

இந்த book கற்றுக்கொடுத்தால் புரியும்:

CPU cache  
memory latency  
assembly  
compiler behavior

இவை தான்:

low latency engineering foundation

----------

# Example knowledge you gain

Example problem:

Why is this loop slow?

Normal programmer:

don't know

Systems programmer:

cache miss  
branch misprediction  
memory latency

புரியும்.

----------

# Industry reputation

இந்த book usually called:

CSAPP

பல top universities use செய்கின்றன:

-   Carnegie Mellon University
    
-   Massachusetts Institute of Technology
    

----------

# Short summary

Book teaches:

How software interacts with hardware

Languages used:

C  
Assembly

Purpose:

build systems programming knowledge

----------

💡 Interesting fact:

பல **low-latency engineers** சொல்வது:

> “CSAPP changed how I think about programs.”
