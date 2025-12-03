#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Structure to represent a region
struct Region {
    int regionID;
    string regionName;
    int population;
    int riskFactor;  // (1 - 100)
    int allocated;   // vaccines allocated
};

// Class to manage vaccine distribution
class VaccineDistribution {
private:
    vector<Region> regions;
    int totalVaccines;  // total stock available

public:
    VaccineDistribution() {
        totalVaccines = 0; // Initially no vaccines
    }

    // Function to add region data
    void addRegion(int id, string name, int population, int risk) {
        Region r;
        r.regionID = id;
        r.regionName = name;
        r.population = population;
        r.riskFactor = risk;
        r.allocated = 0;

        regions.push_back(r);
        cout << "Region " << name << " added successfully!\n";
    }

    // Function to display all regions
    void displayRegions() {
        cout << "\n--- Regions Data ---\n";
        for (auto &r : regions) {
            cout << "ID: " << r.regionID
                 << ", Name: " << r.regionName
                 << ", Population: " << r.population
                 << ", Risk Factor: " << r.riskFactor
                 << ", Allocated: " << r.allocated << "\n";
        }
    }

    // ✅ Function to update vaccine stock
    void updateVaccineSupply(int supply) {
        totalVaccines = supply;
        cout << "Vaccine supply updated! Current stock = " << totalVaccines << " doses.\n";
    }

    // ✅ Function to show current vaccine supply
    void showVaccineSupply() {
        cout << "Available vaccine stock: " << totalVaccines << " doses.\n";
    }

    // ✅ Greedy allocation function
    void allocateVaccines() {
        if (regions.empty()) {
            cout << "No regions available for allocation!\n";
            return;
        }
        if (totalVaccines <= 0) {
            cout << "No vaccines available for allocation!\n";
            return;
        }

        // Reset previous allocations before new distribution
        for (auto &r : regions) r.allocated = 0;

        // Sort regions by Risk Factor (desc), then Population (desc)
        sort(regions.begin(), regions.end(), [](Region &a, Region &b) {
            if (a.riskFactor == b.riskFactor)
                return a.population > b.population; // larger population first
            return a.riskFactor > b.riskFactor; // higher risk first
        });

        cout << "\n--- Vaccine Allocation (Greedy) ---\n";
        for (auto &r : regions) {
            if (totalVaccines == 0) break; // stop if stock finishes

            int allocated = 0;
            if (totalVaccines >= r.population) {
                allocated = r.population;
                totalVaccines -= r.population;
            } else {
                allocated = totalVaccines;
                totalVaccines = 0;
            }

            r.allocated = allocated; // save allocation
            cout << "Region " << r.regionName << " receives " 
                 << allocated << " vaccines.\n";
        }
    }

    // ✅ Report Generation
    void generateReport() {
        cout << "\n====== Vaccine Distribution Report ======\n";

        int totalVaccinated = 0;
        int highRiskPopulation = 0, highRiskVaccinated = 0;

        // 1. List allocations
        for (auto &r : regions) {
            cout << "Region " << r.regionName << " (Pop: " << r.population
                 << ", Risk: " << r.riskFactor << ") -> Vaccinated: "
                 << r.allocated << "\n";

            totalVaccinated += r.allocated;

            // High-risk: Risk factor >= 70
            if (r.riskFactor >= 70) {
                highRiskPopulation += r.population;
                highRiskVaccinated += r.allocated;
            }
        }

        // 2. Regions still needing vaccines
        cout << "\nRegions still needing vaccines:\n";
        bool anyShortage = false;
        for (auto &r : regions) {
            if (r.allocated < r.population) {
                cout << "- " << r.regionName << " needs "
                     << (r.population - r.allocated) << " more.\n";
                anyShortage = true;
            }
        }
        if (!anyShortage) cout << "All regions fully covered!\n";

        // 3. Remaining stock
        cout << "\nRemaining vaccine stock = " << totalVaccines << " doses.\n";

        // 4. Total vaccinated
        cout << "Total people vaccinated = " << totalVaccinated << "\n";

        // 5. High-risk coverage
        double highRiskCoverage = (highRiskPopulation == 0) ? 0.0 :
                                  (highRiskVaccinated * 100.0 / highRiskPopulation);
        cout << "High-risk coverage = " << highRiskCoverage << "% (" 
             << highRiskVaccinated << "/" << highRiskPopulation << ")\n";
        cout << "=========================================\n";
    }
};

int main() {
    VaccineDistribution system;

    // Adding sample region data
    system.addRegion(1, "North City", 50000, 80);
    system.addRegion(2, "South Village", 20000, 60);
    system.addRegion(3, "East Town", 30000, 90);
    system.addRegion(4, "West District", 40000, 90);

    // Update vaccine stock
    system.updateVaccineSupply(90000);

    // Allocate Greedy
    system.allocateVaccines();

    // Generate report
    system.generateReport();

    return 0;
}