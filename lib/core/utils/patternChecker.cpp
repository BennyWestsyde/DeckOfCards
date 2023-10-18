//
// Created by Bennett Westfall on 10/16/23.
//

#include "patternChecker.h"

patternChecker::patternChecker() = default;

Rule::Rule(Rule::RuleType ruleType, int numCards) {
    this->ruleType = ruleType;
    this->numCards = numCards;
}

Rule::Rule(Rule::RuleType ruleType, int numCards, int points) {
    this->ruleType = ruleType;
    this->numCards = numCards;
    this->points = points;
}

bool Rule::checkRule(Set &cards) {


    return false;
}