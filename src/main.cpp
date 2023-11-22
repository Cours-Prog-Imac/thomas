#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <complex>

void vert(sil::Image &image) {
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 0.f;
            image.pixel(x, y).b = 0.f;
        }
    }
}

void echange(sil::Image &image) {
    for (glm::vec3& color : image.pixels()) {
        float b = color.b;
        color.b = color.r;
        color.r = b;
    }
}

void noir_blanc(sil::Image &image) {
    for (glm::vec3& color : image.pixels()) {
        float avg = (color.r + color.b + color.g) / 3;
        color.r = avg;
        color.b = avg;
        color.g = avg;
    }
}

void negatif(sil::Image &image) {
    for (glm::vec3& color : image.pixels()) {
        color.r = 1 - color.r;
        color.b = 1 - color.b;
        color.g = 1 - color.b;
    }
}

void degrade(sil::Image &image) {
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

void miroir(sil::Image &image) {

    sil::Image copie = image;

    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++)
        {
            
            image.pixel(x, y) = copie.pixel(image.width() - x - 1, y);
        }
    }
}

void bruit(sil::Image &image) {
    for (glm::vec3& color : image.pixels()) {
        if (random_int(1,4) == 2) {
            color.r = random_float(0,1);
            color.b = random_float(0,1);
            color.g = random_float(0,1);
        }
    }
}

void rotation(sil::Image &image) {
    
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

void rgb_split(sil::Image &image) {
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

void luminosite(sil::Image& image) {
    for (glm::vec3& color : image.pixels()) {
        color.r = color.r - 0.1;
        color.b = color.b - 0.1;
        color.g = color.g - 0.1;
    }
}


void disque(sil::Image& image) {

    int x_m = image.width()/2;
    int y_m = image.height()/2;

    float rayon = 100;

    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++) {
            // Calcul distance entre centre et le point

            float distance = sqrt(pow(x - x_m, 2) + pow(y - y_m, 2));
            if (distance < rayon) {
                image.pixel(x, y).r = 1;
                image.pixel(x, y).b = 1;
                image.pixel(x, y).g = 1;
            } else {
                image.pixel(x, y).r = 0;
                image.pixel(x, y).b = 0;
                image.pixel(x, y).g = 0;
            }

        }
    }
}

void cercle(sil::Image &image) {
    int x_m = image.width()/2;
    int y_m = image.height()/2;

    float rayon = 100;

    // Pareil que exo11 mais pour un cercle cette fois ci
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++) {

            // Calcul distance entre centre et le point
            float distance = sqrt(pow(x - x_m, 2) + pow(y - y_m, 2));

            // Si la distance est égale au rayon, on est sur le cercle
            if (distance >= rayon - 1 && distance <= rayon + 1) {
                image.pixel(x, y).r = 1;
                image.pixel(x, y).b = 1;
                image.pixel(x, y).g = 1;
            } else {
                image.pixel(x, y).r = 0;
                image.pixel(x, y).b = 0;
                image.pixel(x, y).g = 0;
            }

        }
    }
}


void glitch(sil::Image &image) {
    int glitch_count = 100;
    sil::Image copie = image;

    for (int i = 0; i < glitch_count; i++) {
        // Choisit une taille de rectangle random: largeur entre 5 et 30, hauteur entre 2 et 10
        int largueur = random_int(5,30);
        int hauteur = random_int(2,10);


        // Choisit le x/y du premier rectangle
        int x_1  = random_int(0, image.width() - largueur);
        int y_1  = random_int(0, image.height() - hauteur);

        // Choisit le x/y du deuxième réctangle
        int x_2  = random_int(0, image.width() - largueur);
        int y_2  = random_int(0, image.height() - hauteur);

        for (int x = 0; x < largueur; x++) {
            for (int y = 0; y < hauteur; y++) {

                // Assigne premier rectangle
                image.pixel(x_1 + x, y_1 + y) = copie.pixel(x_2 + x, y_2 + y);

                // Assigne second rectangle
                image.pixel(x_2 + x, y_2 + y) = copie.pixel(x_1 + x, y_1 + y);
            }
        }

    }

}

void contraste(sil::Image &image) {
    // On trouve le px le plus sombre
    float sombre_avg = 1;

    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++) {
            float avg = (image.pixel(x, y).r + image.pixel(x, y).b + image.pixel(x, y).g) / 3;
            if (avg < sombre_avg) {
                sombre_avg = avg;
            }
        }
    }

    // Pixel le plus clair
    float clair_avg = 0;

    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++) {
            float avg = (image.pixel(x, y).r + image.pixel(x, y).b + image.pixel(x, y).g) / 3;
            if (avg > clair_avg) {
                clair_avg = avg;
            }
        }
    }

    // On applique la transfo à tous les pixels
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++) {

            // Avg actuel du pixel
            float avg = (image.pixel(x, y).r + image.pixel(x, y).b + image.pixel(x, y).g) / 3;

            // Nouveau average du pixel
            float new_avg = (avg - sombre_avg) / (clair_avg - sombre_avg);

            // On modifie chaque couleur en faisant une règle de 3
            image.pixel(x, y).r = (image.pixel(x, y).r * new_avg) / avg;
            image.pixel(x, y).b = (image.pixel(x, y).b * new_avg) / avg;
            image.pixel(x, y).g = (image.pixel(x, y).g * new_avg) / avg;

        }
    }
}


int main()
{
    //sil::Image image{300/*width*/, 200/*height*/};
    //sil::Image image{"images/photo.jpg"}; // 300x345

    sil::Image image{"images/photo_faible_contraste.jpg"}; // 300x345

    contraste(image);

    image.save("output/contraste.png");
}