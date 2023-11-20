#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"

void exo1(sil::Image &image) {
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 0.f;
            image.pixel(x, y).b = 0.f;
        }
    }
}

void exo2(sil::Image &image) {
    for (glm::vec3& color : image.pixels()) {
        float b = color.b;
        color.b = color.r;
        color.r = b;
    }
}

void exo3(sil::Image &image) {
    for (glm::vec3& color : image.pixels()) {
        float avg = (color.r + color.b + color.g) / 3;
        color.r = avg;
        color.b = avg;
        color.g = avg;
    }
}

void exo4(sil::Image &image) {
    for (glm::vec3& color : image.pixels()) {
        color.r = 1 - color.r;
        color.b = 1 - color.b;
        color.g = 1 - color.b;
    }
}

void exo5(sil::Image &image) {
    for (int x{0}; x < image.width(); x++) {

        // Calcul de la couleur
        float intensity = x/(float)image.width();

        for (int y{0}; y < image.height(); y++)
        {
            
            image.pixel(x, y).r = intensity;
            image.pixel(x, y).b = intensity;
            image.pixel(x, y).g = intensity;
        }
    }
}

void exo6(sil::Image &image) {

    sil::Image copie = image;

    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++)
        {
            
            image.pixel(x, y) = copie.pixel(image.width() - x - 1, y);
        }
    }
}

void exo7(sil::Image &image) {
    for (glm::vec3& color : image.pixels()) {
        if (random_int(1,4) == 2) {
            color.r = random_float(0,1);
            color.b = random_float(0,1);
            color.g = random_float(0,1);
        }
    }
}

void exo8(sil::Image &image) {
    
    // nouvelle image avec la bonne taille
    sil::Image new_img{image.height()/*width*/, image.width()/*height*/};

    for (int x{0}; x < new_img.width(); x++) {
        for (int y{0}; y < new_img.height(); y++)
        {
            new_img.pixel(x, y) = image.pixel(new_img.height() - y -1, x);
            
        }
    }

    image = new_img;
}

void exo9(sil::Image &image) {
    sil::Image new_img{image.width(), image.height()};

    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++) {

            new_img.pixel(x, y).g = image.pixel(x, y).g;

            // Gère la valeur rouge en vérifiant les limites pour x - 10
            if (x >= 10) {
                new_img.pixel(x, y).r = image.pixel(x - 10, y).r;
            } else {
                // Gérer le cas où x est trop près du bord gauche
                // Par exemple, utiliser la valeur rouge du pixel original
                new_img.pixel(x, y).r = image.pixel(x, y).r;
            }

            // Gère la valeur bleue en vérifiant les limites pour x + 10
            if (x < image.width() - 10) {
                new_img.pixel(x, y).b = image.pixel(x + 10, y).b;
            } else {
                // Gérer le cas où x est trop près du bord droit
                // Par exemple, utiliser la valeur bleue du pixel original
                new_img.pixel(x, y).b = image.pixel(x, y).b;
            }

        }
    }

    image = new_img;
}

void exo10(sil::Image& image) {
    for (glm::vec3& color : image.pixels()) {
        color.r = color.r - 0.1;
        color.b = color.b - 0.1;
        color.g = color.g - 0.1;
    }
}


void exo11(sil::Image& image) {

}


int main()
{
    //sil::Image image{300/*width*/, 200/*height*/};
    //sil::Image image{"images/photo.jpg"}; // 300x345

    sil::Image image{500/*width*/, 500/*height*/};

    exo11(image);

    image.save("output/exo11.png");
}