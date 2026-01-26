class ParkingSystem {
public:
    int one, two, three;
    ParkingSystem(int big, int medium, int small) {
        one = big, two = medium, three = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            return (one > 0 ) ? (one-- || true) : false;
        }else if (carType == 2) {
            return (two > 0 ) ? (two-- || true) : false;
        }else {
            return (three > 0 ) ? (three-- || true) : false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */