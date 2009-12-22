#include "dma.hpp"

using namespace std;

DMA::DMA(boost::shared_ptr<Bus> b) {
  bus = b;
}

uint8_t DMA::bus_read(uint16_t addr){
  return 0;
}

void DMA::bus_write(uint16_t addr, uint8_t val) {
  cout << "DMA: Transfer started at 0x" << hex << (int)(val << 8) << endl;
  if(addr == 0x4014) {
    bus->write(0x2003, 0);
    for(int i = 0; i < 0xFF; i++) {
      bus->write(0x2004, bus_read((val << 8) | i));
    }
  }
}
