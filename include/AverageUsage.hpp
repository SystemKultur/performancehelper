#pragma once
#include <cstdint>
#include <iostream>
#include <string>

namespace systemkultur
{

  class AverageUsage
  {
    private:
      float _cpu;
      float _memory;
    public:
      AverageUsage( const float cpu, const float memory);
      float cpu() const;
      float memory() const;

      static const AverageUsage create_from_proc();
  };
}

std::ostream& operator<<( std::ostream&, const systemkultur::AverageUsage&);
