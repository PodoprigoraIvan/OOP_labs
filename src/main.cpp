#include <iostream>
#include "../include/Cell.hpp"
#include "../include/Field.hpp"
#include "../include/Jumper.hpp"
#include "../include/Fatty.hpp"
#include "../include/MagicTower.hpp"
#include "../include/Trap.hpp"
#include "../include/Grindstone.hpp"

using namespace std;

int main(){
    Field f(10, 10);
    Jumper j(3, 3, &f, 10, 2, 1);
    Player p(0, 0, &f, 10, 100, 2);
    Trap trap(6, 6, &f);
    
    while (1){
        char c;
        cin >> c;
        if (c == 'w') p.move(UP);
        if (c == 's') p.move(DOWN);
        if (c == 'd') p.move(RIGHT);
        if (c == 'a') p.move(LEFT);
        if (c == 't') p.attack(UP);
        if (c == 'g') p.attack(DOWN);
        if (c == 'f') p.attack(RIGHT);
        if (c == 'h') p.attack(LEFT);
        if (j.is_alive()) j.next_action(p);
        for (int y = 0; y < f.get_height(); y++){
            for (int x = 0; x < f.get_width(); x++){
                if (f.get_cell(x, y).is_free()){
                    cout << ' ' << ' ';
                } else {
                    if (dynamic_cast<Player*>(&(f.get_cell(x, y).get_entity())) != nullptr)
                        cout << 'P' << ' ';
                    if (dynamic_cast<Jumper*>(&(f.get_cell(x, y).get_entity())) != nullptr)
                        cout << 'J' << ' ';
                    if (dynamic_cast<Fatty*>(&(f.get_cell(x, y).get_entity())) != nullptr)
                        cout << 'F' << ' ';
                    if (dynamic_cast<Trap*>(&(f.get_cell(x, y).get_entity())) != nullptr)
                        cout << 'T' << ' ';
                }
            }
            cout << '\n';
        }
        cout << "hp: " << p.get_hp() << '\n';
    }
    
    return 0;
}
