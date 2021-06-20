class Solution {
public:
    bool isValid(string expr) 
    {
        stack<char> s;
        char x;

        for (int i = 0; i < expr.length(); i++)
        {
            if (expr[i] == '(' || expr[i] == '['
                || expr[i] == '{')
            {
                // Push the element in the stack
                s.push(expr[i]);
                continue;
            }

            // IF current current character is not opening
            // bracket, then it must be closing. So stack
            // cannot be empty at this point.
            if (s.empty())
                return false;

            switch (expr[i]) {
            case ')':

                x = s.top();
                s.pop();
                if (x == '{' || x == '[')
                    return false;
                break;

            case '}':

                x = s.top();
                s.pop();
                if (x == '(' || x == '[')
                    return false;
                break;

            case ']':               
                x = s.top();
                s.pop();
                if (x == '(' || x == '{')
                    return false;
                break;
            }
        }

        // Check Empty Stack
        return (s.empty());
        
    }
};