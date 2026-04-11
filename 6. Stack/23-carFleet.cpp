// Car Fleet
// you are given:
//  target -> destinationn position
//  position -> starting position of cars
//  speed -> speed of cars
// return:
//  number of car fleets that will arrive at the destination
// car fleet -> a car fleet is a group of cars traveling together at the same speed after  catching up
// cars cannot overtake, but they can catch up and merge
// example -> input: target = 12
//                   position = [10, 8, 0, 5, 3]
//                   speed = [2, 4, 1, 1, 3]
//            output: 3

// idea ->
// compute:
//  time to reach target:
//  time = (target - position) / speed
// then:
//  process cars from nearest to target -> farthest
// if:
//  current time > previous time
//      -> new fleet
// else
//      -> joins existing fleet

#include <bits/stdc++.h>
using namespace std;

// optimal
// complexity: time O(n logn), space: O(n)
// pair position and seed
// sort by position descending
// compute arrival time
// use stack logic to count fleets
int carFleet (int target, vector<int> &position, vector<int> &speed) {
    int n = position.size();
    vector<pair<int, double>> cars;
    for (int i = 0; i < n; i++) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }
    sort(cars.begin(), cars.end(), greater<>());
    int fleets = 0;
    double lastTime = 0;
    for (auto &car : cars) {
        if (car.second > lastTime) {
            fleets++;
            lastTime = car.second;
        }
    }
    return fleets;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int target = 12;

    vector<int> position =
        {
            10, 8, 0, 5, 3};

    vector<int> speed =
        {
            2, 4, 1, 1, 3};

    cout << carFleet(
        target,
        position,
        speed);
    return 0;
}