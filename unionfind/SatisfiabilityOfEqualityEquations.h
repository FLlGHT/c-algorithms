//
// Created by fedorenko on 26.09.2022.
//

#ifndef C_ALGORITMS_SATISFIABILITYOFEQUALITYEQUATIONS_H
#define C_ALGORITMS_SATISFIABILITYOFEQUALITYEQUATIONS_H
#include <iostream>
#include <vector>
#include <wsman.h>
using namespace std;

class SatisfiabilityOfEqualityEquations {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> groups = createGraph();

        for (const auto &equation: equations) {
            int first = equation[0] - 'a', second = equation[3] - 'a';
            bool isEqual = equation[1] == '=';
            if (isEqual)
                merge(first, second, groups);
        }

        for (const auto &equation: equations) {
            int first = equation[0] - 'a', second = equation[3] - 'a';
            bool isEqual = equation[1] == '=';
            if (!isEqual && find(first, groups) == find(second, groups))
                return false;
        }

        return true;
    }
private:
    vector<int> createGraph() {
        vector<int> groups(26);

        for (int i = 0; i < 26; ++i) {
            groups[i] = i;
        }

        return groups;
    }

private:
    void merge(int firstVariable, int secondVariable, vector<int>& groups) {
        int firstGroup = find(firstVariable, groups);
        int secondGroup = find(secondVariable, groups);

        if (firstGroup != secondGroup)
            groups[firstGroup] = secondGroup;
    }

private:
    int find(int variable, vector<int>& groups) {
        if (groups[variable] == variable)
            return variable;

        return find(groups[variable], groups);
    }
};


#endif //C_ALGORITMS_SATISFIABILITYOFEQUALITYEQUATIONS_H
