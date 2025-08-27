#include <iostream>
#include <string>
#include <unordered_map>




int main(){
    std::unordered_map<std::string, int> mpp;
    mpp["Tetrahedron"] = 4;
    mpp["Cube"] = 6;
    mpp["Octahedron"] = 8;
    mpp["Dodecahedron"] = 12;
    mpp["Icosahedron"] = 20;
    
    int no_polyhedrons;
    std::cin >> no_polyhedrons;
    int no_faces = 0;

    for(int idx = 0 ; idx < no_polyhedrons ; idx++){
        std::string polyhedron;
        std::cin >> polyhedron;
        no_faces += mpp[polyhedron];
    }

    std::cout << no_faces;
    return 0;
}