// PIC A 4 MHZ,LEDS NO PORTB B(RB6 E RB7)
// RB7 = LED DE ENUMERA��O OK
// RB6 LED TESTE
// ARQUIVO 'usb_desc_hid 8_byte.h',� UM DESCRIPTOR MODIFICADO PARA 8 X 8

#include <18F2550.h>
#fuses XTPLL,NOWDT,NOPROTECT,LVP,NODEBUG,USBDIV,PLL1,CPUDIV2,VREGEN
#use delay(clock=48000000)

#DEFINE USB_HID_DEVICE TRUE 
#define USB_USE_FULL_SPEED TRUE
#define USB_EP1_TX_ENABLE  USB_ENABLE_INTERRUPT   //turn on EP1 for IN bulk/interrupt transfers 
#define USB_EP1_TX_SIZE    8  //allocate 8 bytes in the hardware for transmission 
#define USB_EP1_RX_ENABLE  USB_ENABLE_INTERRUPT   //turn on EP1 for OUT bulk/interrupt transfers 
#define USB_EP1_RX_SIZE    8  //allocate 8 bytes in the hardware for reception 
#include "pic18_usb.h"   //Microchip 18Fxx5x hardware layer for usb.c 
#include <usb_desc_hid 8_byte.h>   //USB Configuration and Device descriptors for this UBS device
#include "usb.c"        //handles usb setup tokens and get descriptor reports 

////////////////////////////////////////////////////////////////////////////////

void usb_debug_task(void) { 
   int8 last_connected,last_enumerated,new_connected,new_enumerated; 

   new_connected=usb_attached(); 
   new_enumerated=usb_enumerated(); 

   if (new_enumerated) 
      OUTPUT_HIGH(PIN_B7); 
   else 
      OUTPUT_LOW(PIN_B7); 
   last_connected=new_connected; 
   last_enumerated=new_enumerated; 
}

void main(void){     //programa principal 

   int8 in_data[USB_EP1_RX_SIZE];
//   int8 out_data[USB_EP1_TX_SIZE];
 
   usb_init(); 
    while(true)                      //la�o principal do programa 
        { 
        usb_task();
        usb_debug_task(); 
        if (usb_enumerated()) 
           { 
            if (usb_kbhit(1)) 
              { 
                usb_get_packet(1, in_data,USB_EP1_RX_SIZE);
                if (in_data[0] =='1'){OUTPUT_HIGH(PIN_B6);};
                if (in_data[0] =='2'){OUTPUT_LOW(PIN_B6);};  
             } 
          }   
        }
}
