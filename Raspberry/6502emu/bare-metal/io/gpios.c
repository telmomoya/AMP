// 2016 Telmo Moya
#define DUALCORE
#include <stdio.h>
#include <stdint.h>

extern int micro;
uint16_t proxima;

void initialize_buses_pins (void){
//Bus de Datos: D0 a D7 en P2.0 - P2.7
// Inicialización bus de datos (sólo una vez)
/*
	PINSEL4 = 0x00000000;				// Todos los pines del puerto 2 Como GPIO (bus de datos)
	FIO2MASK= 0XFFFF0000;				// Enmascara P2.0 a P2.15  para que se pueda leer y escribir (incluye bus de datos:P2.0 a P2.7 y Bus de Control)
	PINMODE4= 0x0000AAAA;				// P2.0 a P2.15 sin pull-up ni pull-down (bus de datos)
	FIO2DIR0 = 0x00;					// Bus de datos como Entrada

//Bus de Direcciones A0 a A13 en P1.18 - P1.31 + A14 y A15 en P2.11 y P2.12
// Inicialización bus de direcciones (sólo una vez)

	PINSEL3 = 0x00000000;		// Todos los pines del puerto 1 Como GPIO (bus de direcciones)
	PINMODE3= 0xAAAAAAA0;		// P1.18 a P1.31 sin pull-up ni pull-down bus de direcciones)
	FIO1MASK= 0X0003FFFF;		// Enmascara bus de direcciones (P1.18 a P1.31) para que se pueda leer y escribir
	FIO1DIRH= 0XFFFC;			// Bus de direcciones como salida (P1.18 a P1.31)
	PINSEL9 = 0x00000000;		// Los pines upper half del puerto 4 Como GPIO (direcciones A14 y A15)
	FIO4MASK= 0XCFFFFFFF;		// Enmascara A14 Y A15 (P4.28 a P4.29) para que se pueda leer y escribir
	FIO4DIRH= 0X3000;			// A14 y A15 como salida (P4.28 a P4.29)


//Bus de control y Px conectados a P2.8 - P2.13
//Inicialización bus de control (sólo una vez)

	FIO2DIR0 = 0x00;			// Bus de datos como Entrada
	FIO2DIR &= ~(1 << 8);		// Fi0 como entrada (P2.8)
	FIO2DIR |= (1 << 10);		// RW* como salida (P2.10)
	FIO2DIR |= (1 << 11);		// LORAM:P0 como salida (P2.11)
	FIO2DIR |= (1 << 12);		// HIRAM:P1 como salida (P2.12)
	FIO2DIR |= (1 << 13);		// CHAREN:P2 como salida (P2.13)
	FIO2CLR	= (1 << 9);			// Pone en L Fi2 (P2.9)
	FIO2CLR	= (1 << 10);		// Pone en L W (P2.10) Lectura
	FIO2SET	= (1 << 11);		// Pone en H LORAM
	FIO2SET	= (1 << 12);		// Pone en H HIRAM
	FIO2SET	= (1 << 13);		// Pone en H CHAREN
*/
}


//Lectura de memoria
uint8_t externalread(uint16_t address) {
	uint8_t  value;
/*
if (address!=proxima){
    if ((FIO2PIN1&1)==0){
    	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
    }
	proxima = address+1;
    if ((FIO2PIN1&1)==1){
	while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1
	}

	FIO1PINH =(address << 2);	// Escribe la dirección A0 a A13 en P1.18 a P1.31 (bus de direcciones)
	FIO4PINH= (address >> 2);	// A14 y A15 en P4.28 y P4.29

	while ((FIO0PIN3&16)==0){};	// Si RDY=0 (P0.28) espero aquí

    if ((FIO2PIN1&1)==0){
    	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
    }
	if ((FIO2PIN1&1)==1){
	while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1
	}
	value = FIO2PIN0; 			// Lee bus de datos (P2.0 a P2.7)
//	DEBUGOUT ("<> %x %x\n",address,value);
}
else{

   if ((FIO2PIN1&1)==0){
    	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
    }
	proxima = address+1;
	if ((FIO2PIN1&1)==1){
	while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1
	}

	if ((FIO0PIN3&16)==0){
		while ((FIO0PIN3&16)==0){};	// Si RDY=0 (P0.28) espero aquí
		while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0/////////////
		while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1/////////////
	};	// Si RDY=0 (P0.28)
	value = FIO2PIN0; 			// Lee bus de datos (P2.0 a P2.7)
//	DEBUGOUT ("== %x %x\n",address,value);
}
	FIO1PINH =(proxima << 2);	// Escribe la dirección A0 a A13 en P1.18 a P1.31 (bus de direcciones)
	FIO4PINH= (proxima >> 2);	// A14 y A15 en P4.28 y P4.29
*/
	return(value);
}


//Escritura de memoria
void externalwrite(uint16_t address, uint8_t value) {
/*
#ifdef DUALCORE
	if (address==0xde00) {			// CPM cartridge: change micro address
		micro = (value & 0x1);
	}
#endif
	if (address==0x1) {				// 6510 I/O Port write address
		if ((value & 0x1)==0){
			FIO2CLR	= (1 << 11);		// Pone en L LORAM
		}
		else
		{
			FIO2SET	= (1 << 11);		// Pone en H LORAM
		}

		if ((value & 0x2)==0){
			FIO2CLR	= (1 << 12);		// Pone en L HIRAM
		}
		else
		{
			FIO2SET	= (1 << 12);		// Pone en H HIRAM
		}

		if ((value & 0x4)==0){
			FIO2CLR	= (1 << 13);
		}
		else
		{
			FIO2SET	= (1 << 13);		// Pone en H CHAREN
			}
	}
	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
	FIO2PIN0 = value;    		// Escribe bus de datos (P2.0 a P2.7)
	proxima = address;
	while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1


////////////////////FLANCO DESCENDENTE////////////////////
	FIO1PINH =(address << 2);	// Escribe la dirección A0 a A13 en P1.18 a P1.31 (bus de direcciones)
	FIO4PINH= (address >> 2);	// A14 y A15 en P4.28 y P4.29
	FIO2SET	= (1 << 10);		// Pone en H W (P2.10) Escritura
    FIO2DIR0 = 0xff; 		    // Bus de datos como Salida
   	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
	while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1

	////////////////////FLANCO DESCENDENTE////////////////////
	FIO2PIN0 = value;    		// Escribe bus de datos (P2.0 a P2.7)
	FIO2DIR0 = 0x00;			// Bus de datos como Entrada
	FIO2CLR	= (1 << 10);		// Pone en L W (P2.10) Lectura

//	FIO1PINH =(proxima << 2);	// Escribe la dirección A0 a A13 en P1.18 a P1.31 (bus de direcciones)
//	FIO4PINH= (proxima >> 2);	// A14 y A15 en P4.28 y P4.29

*/
}

//Lectura de memoria 16 bits
uint16_t ext16read(uint16_t address) {

	uint8_t  value_low, value_high;
/*
if (address!=proxima){

	    if ((FIO2PIN1&1)==0){
	    	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
	    }
		proxima = address+1;
	    if ((FIO2PIN1&1)==1){
		while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1
		}

		FIO1PINH =(address << 2);	// Escribe la dirección A0 a A13 en P1.18 a P1.31 (bus de direcciones)
		FIO4PINH= (address >> 2);	// A14 y A15 en P4.28 y P4.29

		while ((FIO0PIN3&16)==0){};	// Si RDY=0 (P0.28) espero aquí

	    if ((FIO2PIN1&1)==0){
	    	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
	    }
		if ((FIO2PIN1&1)==1){
		while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1
		}
	value_low = FIO2PIN0; 		// Lee bus de datos (P2.0 a P2.7)
	FIO1PINH =(proxima << 2);	// Escribe la dirección A0 a A13 en P1.18 a P1.31 (bus de direcciones)
	FIO4PINH= (proxima >> 2);	// A14 y A15 en P4.28 y P4.29

// READ HIGH BYTE
    if ((FIO2PIN1&1)==0){
    	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
    }
	proxima = address+2;
	if ((FIO2PIN1&1)==1){
	while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1
	}
	if ((FIO0PIN3&16)==0){
		while ((FIO0PIN3&16)==0){};	// Si RDY=0 (P0.28) espero aquí
		while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0/////////////
		while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1/////////////
	};	// Si RDY=0 (P0.28)
	value_high = FIO2PIN0; 			// Lee bus de datos (P2.0 a P2.7)
	FIO1PINH =(proxima << 2);	// Escribe la dirección A0 a A13 en P1.18 a P1.31 (bus de direcciones)
	FIO4PINH= (proxima >> 2);	// A14 y A15 en P4.28 y P4.29
	}

else{
// READ LOW BYTE
    if ((FIO2PIN1&1)==0){
    	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
    }
	proxima = address+1;
	if ((FIO2PIN1&1)==1){
	while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1
	}
	if ((FIO0PIN3&16)==0){
		while ((FIO0PIN3&16)==0){};	// Si RDY=0 (P0.28) espero aquí
		while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0/////////////
		while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1/////////////
	};	// Si RDY=0 (P0.28)
	value_low = FIO2PIN0; 			// Lee bus de datos (P2.0 a P2.7)
	FIO1PINH =(proxima << 2);	// Escribe la dirección A0 a A13 en P1.18 a P1.31 (bus de direcciones)
	FIO4PINH= (proxima >> 2);	// A14 y A15 en P4.28 y P4.29
// READ HIGH BYTE
    if ((FIO2PIN1&1)==0){
    	while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0
    }
	proxima = address+2;
	if ((FIO2PIN1&1)==1){
	while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1
	}
	if ((FIO0PIN3&16)==0){
		while ((FIO0PIN3&16)==0){};	// Si RDY=0 (P0.28) espero aquí
		while ((FIO2PIN1&1)==0) {};	// Espera mientras AEC=0 -> Fi0(P2.8)=0/////////////
		while ((FIO2PIN1&1)==1) {};	// Espera mientras AEC=1 -> Fi0(P2.8)=1/////////////
	};	// Si RDY=0 (P0.28)
	value_high = FIO2PIN0; 			// Lee bus de datos (P2.0 a P2.7)
	FIO1PINH =(proxima << 2);	// Escribe la dirección A0 a A13 en P1.18 a P1.31 (bus de direcciones)
	FIO4PINH= (proxima >> 2);	// A14 y A15 en P4.28 y P4.29
}
*/
return((uint16_t)value_low | ((uint16_t)value_high << 8));

}
