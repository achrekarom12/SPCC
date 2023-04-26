import java.util.*;

public class ICG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an arithmetic expression: ");
        String expr = sc.nextLine();

        Stack<String> operands = new Stack<String>();
        Stack<Character> operators = new Stack<Character>();
        int tempNum = 1;

        for (int i = 0; i < expr.length(); i++) {
            char ch = expr.charAt(i);

            if (Character.isLetterOrDigit(ch)) {
                operands.push(String.valueOf(ch));
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
                while (!operators.empty() && hasHigherPrecedence(operators.peek(), ch)) {
                    String tempVar2 = operands.pop();
                    String tempVar1 = operands.pop();
                    String tempResult = "t" + tempNum++;
                    System.out.println(tempResult + " = " + tempVar1 + " " + operators.pop() + " " + tempVar2);
                    operands.push(tempResult);
                }
                operators.push(ch);
            }
        }

        while (!operators.empty()) {
            String tempVar2 = operands.pop();
            String tempVar1 = operands.pop();
            String tempResult = "t" + tempNum++;
            System.out.println(tempResult + " = " + tempVar1 + " " + operators.pop() + " " + tempVar2);
            operands.push(tempResult);
        }

        System.out.println("Result: " + operands.pop());
    }

    public static boolean hasHigherPrecedence(char op1, char op2) {
        if ((op1 == '*' || op1 == '/' || op1 == '%') && (op2 == '+' || op2 == '-')) {
            return true;
        } else {
            return false;
        }
    }
}
