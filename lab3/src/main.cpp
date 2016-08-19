
#include "adc.h"
#include "master_adc.cpp"
#include "slave_adc.cpp"

SC_MODULE(Top)
{
  Master_ADC *master;
  Slave_ADC  *slave;

  SC_CTOR(Top)
  {
    // Instantiate components
    master = new Master_ADC("initiator");
    slave  = new Slave_ADC("memory");

    // One initiator is bound directly to one target with no intervening bus
    // Bind initiator socket to target socket
    master->socket.bind( slave->socket );
  }
};

int sc_main(int argc, char* argv[])
{
  Top top("top");
  sc_start();

  return 0;
}
