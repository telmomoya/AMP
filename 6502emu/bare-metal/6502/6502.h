extern void step6502();
extern void exec6502(uint32_t);

extern uint8_t read6502(uint16_t);
extern void write6502(uint16_t,uint8_t);

extern void reset6502();
extern void nmi6502();
extern void irq6502();


