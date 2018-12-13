#include <map>
#include <sstream>
#include "relation.h"
#include "graph.h"

using namespace std;

class Database {
public:
  Database();
  void doSchemes(vector<Predicate> schemes);
  void doFacts(vector<Predicate> facts);
  void doRules(vector<Rule> rules);
  void doQueries(vector<Predicate> queries);
  bool match(string parameter);
  bool isTrivial(vector<Rule> rules);
  string printRuleResults();
  string printOptimizedRuleResults(vector<Rule> rules);
  string printQueryResults();
  string printTables(); //for testing purposes
private:
  map<string, Relation> tables;
  vector<Rule> rules;
  vector<Relation> queryResults;
  vector<Predicate> queries;
  vector<string> parameterCheck;
  int matchIndex;
  int numRuleEvaluations;
  bool changes;
};
