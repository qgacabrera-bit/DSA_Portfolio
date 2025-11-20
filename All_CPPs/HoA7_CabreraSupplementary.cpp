#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "sortingAlgo.h"

int main() {
    std::vector<int> votes(101);

    std::cout << "Votes casted:\n";
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < 101; ++i) {
        votes[i] = rand() % 5 + 1;
        std::cout << votes[i] << " ";
    }
    std::cout << std::endl << std::endl;

    insertionSort(votes);

    std::cout << "Votes sorted:\n";
    for (int i = 0; i < 101; ++i) {
        std::cout << votes[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Count the votes

    std::vector<int> voteCounts(5, 0);
    for (int vote : votes) {
        if (vote >= 1 && vote <= 5) {
            voteCounts[vote - 1]++;
        }
    }


    int maxVotes = -1;
    int winningCandidateIndex = -1;
    for (int i = 0; i < voteCounts.size(); ++i) {
        if (voteCounts[i] > maxVotes) {
            maxVotes = voteCounts[i];
            winningCandidateIndex = i;
        }
    }

    std::cout << "Vote Results:" << std::endl;
    for (int i = 0; i < candidates.size(); ++i) {
        std::cout << "Candidate " << (i + 1) << " (" << candidates[i] << "): " << voteCounts[i] << " votes" << std::endl;
    }

    std::cout << "\nWinner:" << std::endl;
    if (winningCandidateIndex != -1) {
        std::cout << "Candidate " << (winningCandidateIndex + 1) << " (" << candidates[winningCandidateIndex] << ") with " << maxVotes << " votes." << std::endl;
    }
    else {
        std::cout << "No votes were counted." << std::endl;
    }

    return 0;
}