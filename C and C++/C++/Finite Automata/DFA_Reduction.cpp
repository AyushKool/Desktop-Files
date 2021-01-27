/*
This program performs DFA Minimization based on the Myhill-Narode theorem.
The initial state is assumed to be q0 (first state).

*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef set<si> sii;
typedef vector<vi> vii;

#define present(container, element) (container.find(element) != container.end())

void displayTable(const vii &v, si &finalStates)
{
    cout << "\nTransition Table:\n";
    for (int i = 0; i < v[0].size(); ++i)
        cout << "\t" << i;
    cout << "\n-----------------------------\n>";
    for (int i = 0; i < v.size(); ++i)
    {
        if (i != 0)
            cout << ' ';
        cout << (present(finalStates, i) ? '*' : ' ') << i << " |";
        for (int j = 0; j < v[i].size(); ++j)
            cout << "\t" << v[i][j];
        cout << '\n';
    }
}

void removeFromDFA(vii &dfa, si &finalStates, int state)
{
    dfa.erase(dfa.begin() + state);
    for (int i = 0; i < dfa.size(); ++i)
        for (int j = 0; j < dfa[i].size(); ++j)
            if (dfa[i][j] > state)
                --dfa[i][j];

    for (auto x : finalStates)
    {
        if (x > state)
        {
            finalStates.erase(x);
            finalStates.insert(x - 1);
        }
    }
}

void isReachable(vii &dfa, si &reachable, int ind)
{
    reachable.insert(ind);
    for (auto state : dfa[ind])
    {
        //if state is already in reachable, continue
        if (present(reachable, state))
            continue;
        // reachable.insert(state);
        isReachable(dfa, reachable, state);
    }
}

void removeUnreachable(vii &dfa, si &finalStates)
{
    si reachable;
    isReachable(dfa, reachable, 0);
    for (int i = 0; i < dfa.size(); ++i)
    {
        if (!present(reachable, i))
        {
            removeFromDFA(dfa, finalStates, i);
        }
    }
}

bool isEqiv(vii &dfa, vector<si> &eq, int state1, int state2)
{
    for (int i = 0; i < dfa[0].size(); ++i)
    {
        for (si s : eq)
        {
            if (present(s, dfa[state1][i]) && !present(s, dfa[state2][i]))
                return false;
        }
    }
    return true;
}

int main()
{
    int states, alphabet;
    cout << "Enter the number of states: ";
    cin >> states;
    cout << "Enter the number of symbols in alphabet: ";
    cin >> alphabet;

    vii dfa(states, vi(alphabet, -1));
    si finalStates;

    //Input the DFA and store transitions for each state
    cout << "\nEnter the transitions of each state:\n";
    for (int i = 0; i < states; ++i)
    {
        cout << "State q" << i << ":\n";
        for (int j = 0; j < alphabet; ++j)
        {
            cout << "\tSymbol " << j << ": ";
            cin >> dfa[i][j];
        }
    }

    cout << "\nEnter the no. final states: ";
    int fnum, tmp;
    cin >> fnum;
    cout << "Enter the final states:\n";
    while (fnum--)
    {
        cin >> tmp;
        finalStates.insert(tmp);
    }

    //remove all the unreachable states from dfa
    removeUnreachable(dfa, finalStates);
    // displayTable(dfa, finalStates);
    states = dfa.size();
    //Find non-final states
    si nonfinalStates;
    for (int i = 0; i < states; ++i)
        if (!present(finalStates, i))
            nonfinalStates.insert(i);

    //Minimize the DFA
    vector<si> eq, prevEq;
    eq.push_back(nonfinalStates);
    eq.push_back(finalStates);
    int prevsize, numOfFinalStates = 1;

    do
    {
        // prevsize = eq.size();
        prevEq = eq;
        for (int itr = 0; itr < prevEq.size(); ++itr)
        {
            int first = *(prevEq[itr].begin());
            for (auto i = prevEq[itr].begin(); i != prevEq[itr].end();)
            {
                i++;
                if (i == prevEq[itr].end())
                    break;

                if (isEqiv(dfa, prevEq, first, *i))
                    continue;

                bool flag = true, inNonFinal = (itr < eq.size() - numOfFinalStates);
                int limit = (inNonFinal ?   eq.size() - numOfFinalStates : eq.size());

                for (int tmp = itr + 1; tmp != limit; ++tmp)
                {
                    int firstNum = *(eq[tmp].begin());
                    if (isEqiv(dfa, prevEq, firstNum, *i))
                    {
                        eq[tmp].insert(*i);
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    if(!inNonFinal)
                        numOfFinalStates++;
                    si s2;
                    s2.insert(*i);
                    // eq.push_back(s2);
                    eq.insert(eq.begin()+itr +1, s2);
                }
                // auto prev = i;
                // prev--;
                eq[itr].erase(*i);
                // i = prev;
            }
        }
    } while (prevEq.size() != eq.size() && eq.size() != states);

    // for (si s : eq)
    // {
    //     cout << "{";
    //     for (auto x : s)
    //         cout << x << " ";
    //     cout << "} ";
    // }

    vii min_dfa(eq.size(), vi(alphabet, -1));
    si newFinalStates;
    for (int i = 0; i < eq.size(); ++i)
    {
        si s = eq[i];
        // for (auto x : s)
        //     if (present(finalStates, x))
        //         newFinalStates.insert(i);
        
        if(i >= eq.size() - numOfFinalStates)
            newFinalStates.insert(i);
        int firstNum = *(s.begin());
        for (int k = 0; k < alphabet; ++k)
        {
            for (int j = 0; j < eq.size(); ++j)
                if (present(eq[j], dfa[firstNum][k]))
                    min_dfa[i][k] = j;
        }
    }

    // cout << "\n";
    // for (auto x : newFinalStates)
    //     cout << x << " ";

    cout << "Minimized DFA:\n";
    displayTable(min_dfa, newFinalStates);
}
