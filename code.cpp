#include <iostream>
#include <vector>
#include <string>
using namespace std;
    std::string head;


class Spacecraft {
public:
    int x, y, z;
    std::string direction;
    // static std::string head;

    Spacecraft(int x, int y, int z, std::string direction) : x(x), y(y), z(z), direction(direction) {}

    void move(std::string command) {
        if (command == "f") {
            if (direction == "N") y++;
            else if (direction == "S") y--;
            else if (direction == "E") x++;
            else if (direction == "W") x--;
            else if (direction == "U") z++;
            else if (direction == "D") z--;
        } else if (command == "b") {
            if (direction == "N") y--;
            else if (direction == "S") y++;
            else if (direction == "E") x--;
            else if (direction == "W") x++;
            else if (direction == "U") z--;
            else if (direction == "D") z++;
        }
    }

    // void turn(std::string command,std::string head ) {
    void turn(std::string command) {
        if (command == "l" || command == "r")   //direction changes , head  does not change
        {
            if (direction == "N") direction = (command == "l" ? "W" : "E");
            else if (direction == "S") direction = (command == "l" ? "E" : "W");
            else if (direction == "E") direction = (command == "l" ? "N" : "S");
            else if (direction == "W") direction = (command == "l" ? "S" : "N");
            else if (direction=="U" ) 
            {
                if( head =="S")  direction= (command == "l" ? "W" : "E");
                else if(head =="N")  direction= (command == "l" ? "E" : "W");
                else if(head =="E")  direction= (command == "l" ? "S" : "N");
                else if(head =="W")  direction= (command == "l" ? "N" : "S");
            }
            else if (direction=="D" ) 
            {
                if( head =="N")  direction= (command == "l" ? "W" : "E");
                else if(head =="S")  direction= (command == "l" ? "E" : "W");
                else if(head =="W")  direction= (command == "l" ? "S" : "N");
                else if(head =="E")  direction= (command == "l" ? "N" : "S");
            }   
        }
        

        else if(command=="U" || command=="D") // head  and direction both change
        {
            if (direction == "N" || direction == "E" || direction == "W" || direction == "S" )
            {
                if(direction=="N")  head = ( command=="U"? "S":"N");
                else if(direction=="E")  head = ( command=="U"? "W":"E");
                else if(direction=="W")  head = ( command=="U"? "E":"W");
                else if(direction=="S")  head = ( command=="U"? "N":"S");
                direction = (command == "U" ? "U" : "D");

            } 
            else if(direction=="U" || direction=="D")
            {
                if(direction=="U")
                {
                    head ="D";
                    if(head =="S")  direction=(command=="U"? "S":"N");
                    else if(head =="E")  direction=(command=="U"? "E":"W");
                    else if(head =="N")  direction=(command=="U"? "N":"S");
                    else if(head =="W")  direction=(command=="U"? "W":"E");
                     
                }
                else if(direction=="D")
                {
                    head ="U";
                    if(head =="S")  direction=(command=="U"? "S":"N");
                    else if(head =="E")  direction=(command=="U"? "E":"W");
                    else if(head =="N")  direction=(command=="U"? "N":"S");
                    else if(head =="W")  direction=(command=="U"? "W":"E");
                     
                }
            }
        }
    }

    void executeCommands(std::vector<std::string> commands) {
        for(std::string command : commands) {
            if(command=="f" || command=="b")
                move(command);
            else
                turn(command);
        }
    }
};

int main() {
    Spacecraft spacecraft(0, 1, 1, "N");
    std::vector<std::string> commands = {"l", "r", "U", "f", "D"};

    head  ="U";


    spacecraft.executeCommands(commands);
    std::cout << "(" << spacecraft.x << ", "
              << spacecraft.y << ", "
              << spacecraft.z << ") - "
              << spacecraft.direction << std::endl;
    return 0;
}
