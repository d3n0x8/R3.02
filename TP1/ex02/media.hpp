// media.hpp
#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <string>

class Media {
public:
  Media() = default;
  virtual ~Media() = default;
  virtual std::string getInfo() const = 0;  // Méthode virtuelle pure
  virtual std::string getTitre() const = 0; // Méthode virtuelle pure
};

#endif