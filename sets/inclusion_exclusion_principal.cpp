int n; // the number of sets in the set A
int result = 0; //final result, the cardinality of sum of all subsets of A
for(int b = 0; b < (1 << n); ++b)
{
     vector<int> indices;
     for(int k = 0; k < n; ++k)
     {
          if(b & (1 << k))
          {
               indices.push_back(k);
          }
     }
     int cardinality = intersectionCardinality(indices);
     if(indices.size() % 2 == 1) result += cardinality;
     else result -= cardinality;
}
cout << result << endl; //printing the final result

// Total Number of solutions which satifies all the conditions
N(~C1 ~C2 ~C3) = N - { N(C1)+N(C2)+N(C3) } 
                    + { N(C1 C2)+N(C2 C3)+N(C3 C1) }
                    - N(C1 C2 C3);

               = S0 - S1 + S2 - S3


// Number of Solutions which satisfies exactly m conditions.


Em = Sm - (m+1)Choose1 S(m+1) + (m+2)Choose2 S(m+2) + ..........


// NUmber of Solutions which satisfies at least m conditions.

Lm = Sm - mChoose1 S(m+1) + (m+1)Choose2 S(m+2) - ..........

