#include "ADC_and_LED_blink.h"

unsigned int signal_reading;

void main()
{

   setup_adc_ports(AN0|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
//Setup_Oscillator parameter not selected from Intr Oscillator Config tab

   // TODO: USER CODE!!
   set_adc_channel(0);
   while(true)
   {
      signal_reading = read_adc();
      delay_us(50);
      
      if(signal_reading >= 128)
      {
         output_high(pin_b0);
      }
      else
      {
         output_low(pin_b0);
      }
   }

}
