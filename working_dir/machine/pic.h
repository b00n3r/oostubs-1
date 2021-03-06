/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I C                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __pic_include__
#define __pic_include__
#include "machine/io_port.h"
/**
 * The PIC or Programmable Interrupt Controller enables the system to 
 * allow/forbid interrupts. By allowing an interrupt the PIC defines which
 * interrupts are handled by the system. It is important that interrupts will
 * only be handled if the interrupt has been allowed and if the handling of 
 * interrupts is enabled (see class CPU). 
 */
class PIC {
public:
	enum Device {timer = 0, keyboard = 1, all = 0xFF}; 
	enum {ACK = 0x20};
	PIC();
  /**
   * Method allow() enables the system to handle interrupts of the specified 
   * device useing the PIC. To enable the handleing of any interrupt 
   * CPU::enable_int() has to be called first.
   *
   * @param interrupt_device number of interrupt that will be allowed
   */
	void allow(Device dev);
	
  /**
   * Method forbid() disables the an interrupt useing the PIC.
   * 
   * @param interrupt_device number of interrupt that will be forbiden
   */
	void forbid(Device dev);
  /**
   * Method ack() is used to acknowledge an occured interrupt. An acknowledge
   * tells the PIC that his last interrupt has been handled. This Method has
   * to be called before the cpu is allowed to handle any new interrupts. If
   * an interrupt is not acknowledged the same interrupt is called again and 
   * again
   */
	void ack();
private:
	IO_Port imr_a;
	IO_Port isr_a;
	IO_Port isr_b;
	IO_Port imr_b;
};

#endif
