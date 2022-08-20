#pragma once

#include <iostream>
#include <vector>

class Control
{
 public:
  Control();

  void fore_port(std::vector<double> &target);
  void fore_starboard(std::vector<double> &target);
  void aft_port(std::vector<double> &target);
  void aft_starboard(std::vector<double> &target);

  ~Control();
};
