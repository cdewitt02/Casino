#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;


class Elevator{
private:
    enum Direction {UP, DOWN};
    Direction direction;

    vector<int> requests = {};

    int bottom_floor;
    int top_floor;
    int curr_floor = 0;
    size_t passengers;
    size_t capacity;

    void set_direction(int floor);
    void set_requests();
    int is_valid_request(int floor);


public:

    void start_elevator();

    Elevator(int bottom_floor, int top_floor, size_t capacity){
        this->bottom_floor = bottom_floor;
        this->top_floor = top_floor;
        this->capacity = capacity;
    }
    ~Elevator(){}
};

int Elevator::is_valid_request(int floor) {
    if (passengers != 0 && direction == DOWN && floor > curr_floor){
        cout<<("\nElevator is going DOWN.");
        return 1;
    }
    if (passengers != 0 && direction == UP && floor < curr_floor){
        cout<<("\nElevator is going UP.");
        return 2;
    }
    if (floor > top_floor || floor < bottom_floor){
        cout<<("\nThis floor does not exist.\n");
        return 3;
    }
    return 0;
}

void Elevator::set_direction(int floor) {
    if(floor > curr_floor){
        direction = UP;
    }
    else if(floor < curr_floor){
        direction = DOWN;
    }

}

void Elevator::set_requests() {
    int floor, flag = 1; string action;
    while(passengers <= capacity-1 && flag == 1){
        cout<<("\nEnter CLOSE if no one else gets in on this floor, enter MORE if there are more entries: ");
        cin>>action;for(int i = 0; i < action.size(); i++){
            action[i] = toupper(action[i]);
        }

        if(action == "CLOSE"){
            flag = 0;
            break;
        }
        cout<<("\nEnter floor number: ");
        cin>>floor;
        if(is_valid_request(floor) == 0){
            if(passengers == 0){
                set_direction(floor);
            }
            requests.push_back(floor);
            passengers++;
        }

    }
    if(flag == 1)
        cout<<("\nElevator full!");
    return;
}

int end(){
    char x;
    cout<<("Do you want to continue? (Y/N): ");
    cin >> x;

    if(x == 'y' || x == 'Y'){
        return 0;
    }
    return 1;
}

void Elevator::start_elevator() {
    cout<<("\nFLOOR: ") << bottom_floor << ("\tNUMBER OF PASSENGERS: ") << passengers;

    set_requests();
    sort(requests.begin(), requests.end());
    int next;

    while(!requests.empty()){
        if (direction == UP){
            next = requests[0];
        }
        if (direction == DOWN){
            next = requests[requests.size() - 1];
        }
        auto next_req = find(requests.begin(), requests.end(), next);
        while(next_req != requests.end()){
            requests.erase(next_req);
            passengers--;
            next_req = find(requests.begin(), requests.end(), next);
        }
        curr_floor = next;
        string direc;
        if(curr_floor == top_floor){
            direc = "Down";
        }
        else
            direc = "UP";

        cout << "\n=======================================================\n"
                     "FLOOR : " << curr_floor
                  << "\tNumber of Occupants : " << passengers
                  << "\n\nDIRECTION : " << direc
                  << "\tTotal Capacity : " << capacity
                  << "\n\nMinimum floor number is " << bottom_floor
                  << "\tMaximum floor number is " << top_floor
                  << "\n\n=======================================================\n";

        set_requests();
        sort(requests.begin(), requests.end());
    }


}

void welcome(){
    cout<<("\n========= WELCOME TO THE ELEVATOR PROGRAM =========");
    cout<<("\nAuthor: Charlie DeWitt\t\tDate Published: 10/4/22");
    cout<<("\n\nThis program is based on the logic used in elevators across the world, \nthe user controls all passengers of the elevator.");
    cout<<("\n===================================================\n");
}

int main() {
    welcome();
    int bott_floor, top_floor;
    size_t capacity;
    cout<<("\nEnter in the lowest floor number (use negative number for underground floors): ");
    cin>>bott_floor;
    cout<<("\nEnter in the highest floor number: ");
    cin>>top_floor;
    cout<<("\nEnter in the capacity of the elevator (number of people): ");
    cin>>capacity;

    Elevator elevator(bott_floor, top_floor, capacity);
    elevator.start_elevator();

}
