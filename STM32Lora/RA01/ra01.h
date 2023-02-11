/*
 * ra01.h
 *
 *  Created on: Feb 7, 2023
 *      Author: josep
 */

#ifndef RA01_H_
#define RA01_H_

#include "stm32g4xx_hal.h"
#include "main.h"

#define PA_OUTPUT_RFO_PIN          0
#define PA_OUTPUT_PA_BOOST_PIN     1

class LoRaClass {
public:
  LoRaClass();

  int begin(long frequency);
  void end();

  int beginPacket(int implicitHeader = false);
  int endPacket(bool async = false);

  int parsePacket(int size = 0);
  int packetRssi();
  float packetSnr();
  long packetFrequencyError();

  int rssi();

  // from Print
  virtual size_t write(uint8_t byte);
  virtual size_t write(const uint8_t *buffer, size_t size);

  // from Stream
  virtual int available();
  virtual int read();
  virtual int peek();
  virtual void flush();

//  void onReceive(void(*callback)(int));
//  void onTxDone(void(*callback)());
//  void receive(int size = 0);

  void idle();
  void sleep();

  void setRxMode();

  void setTxPower(int level, int outputPin = PA_OUTPUT_PA_BOOST_PIN);
  void setFrequency(long frequency);
  void setIRQInterrupts();
  void setSpreadingFactor(int sf);
  void setSignalBandwidth(long sbw);
  void setCodingRate4(int denominator);
  void setPreambleLength(long length);
  void setSyncWord(int sw);
  void enableCrc();
  void disableCrc();
  void enableInvertIQ();
  void disableInvertIQ();

  void setOCP(uint8_t mA); // Over Current Protection control

  void setGain(uint8_t gain); // Set LNA gain

  // deprecated
  void crc() { enableCrc(); }
  void noCrc() { disableCrc(); }

  uint8_t random();

//  void setPins(int ss = LORA_DEFAULT_SS_PIN, int reset = LORA_DEFAULT_RESET_PIN, int dio0 = LORA_DEFAULT_DIO0_PIN);
  void setSPI(SPI_HandleTypeDef *spi, GPIO_TypeDef *LORA_CS_GPIO_Port, uint16_t LORA_CS_Pin, GPIO_TypeDef *LORA_BUSY_GPIO_Port, uint16_t LORA_BUSY_Pin);

private:
  void explicitHeaderMode();
  void implicitHeaderMode();

  void handleDio0Rise();
  bool isTransmitting();

  int getSpreadingFactor();
  long getSignalBandwidth();

  void setLdoFlag();

  void checkBusyLine();
  uint8_t readRegister(uint8_t address);
  void writeRegister(uint8_t address, uint8_t value);
  void writeCommand(uint8_t opcode, uint8_t values[], uint8_t valuesLen);
  uint8_t singleTransfer(uint8_t address, uint8_t value);

  static void onDio0Rise();

private:
  SPI_HandleTypeDef* _spi;
  GPIO_TypeDef *_LORA_CS_GPIO_Port;
  uint16_t _LORA_CS_Pin;
  GPIO_TypeDef *_LORA_BUSY_GPIO_Port;
  uint16_t _LORA_BUSY_Pin;
  long _frequency;
  int _packetIndex;
  int _implicitHeaderMode;
  void (*_onReceive)(int);
  void (*_onTxDone)();
};

extern LoRaClass LoRa;

#endif /* RA01_H_ */
