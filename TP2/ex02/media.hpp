// media.hpp
#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <string>
using namespace std;

class Media {
private:
  string type[3] = {"DVD", "Livre", "Vinyle"};

public:
  Media() = default;
  virtual ~Media() = default;
  virtual std::string getInfo() const = 0;  // Méthode virtuelle pure
  virtual std::string getTitre() const = 0; // Méthode virtuelle pure
  virtual std::string getArtiste() const = 0;
  virtual int getAnnee() const = 0;
  virtual std::string getGenre() const = 0;
};

#endif