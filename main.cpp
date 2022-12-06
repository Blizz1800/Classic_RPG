#include <iostream>
#include "ventizca.hpp"

using namespace std;

int main()
{
    if (!al_init())
    {
        e_msg("Error has occurred when initialicing allegro");
        return -1;
    }
    msg("Allegro initialized successfuly");
    if (!al_install_keyboard())
    {
        e_msg("Error has occurred when initialicing allegro");
        return -2;
    }
    e_msg("Keyboard initialized successfuly");

    ALLEGRO_DISPLAY *Display = al_create_display(800, 600);
    if (Display == NULL)
    {
        e_msg("Error has occurred when initialicing allegro");
        return -2;
    }

    al_clear_to_color(al_map_rgb(0x00, 0x00, 0x00));
    al_flip_display();
    msg("Display initialized successfuly");

    if(!al_init_image_addon())
    {
        e_msg("Image addon could't be initialized!!");
        return -3;
    }
    msg("Image addon has be initialized");
    ALLEGRO_BITMAP* firstSplash = al_load_bitmap("./images/splash.png");

    if (firstSplash == NULL)
    {
        e_msg("Image " << "./images/splash.png" << " didn't loaded");
        return -4;
    }
    msg("Image loaded success");
    //al_set_target_bitmap(lienzo);
    al_set_target_backbuffer(Display);
    al_draw_scaled_bitmap(firstSplash, 0, 0, 1920, 1285,0, 0, 800,600, 0);
    al_flip_display();
    al_rest(5);
    for(unsigned char i = 0; i < 70; i++)
    {
        al_draw_tinted_bitmap(firstSplash, al_map_rgba(0x00, 0x00, 0x00, i), 0, 0, 0);
        al_flip_display();
        al_rest(0.05);
        cout << (int) i << endl;
    }

    al_destroy_display(Display);
    return 0;
}
