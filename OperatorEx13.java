/**
 * Created by 민규 on 2017-03-29.
 */
public class OperatorEx13
{
    public static void main(String[] args)  ///args 가 무슨뜻일까???
    {
        char c1 = 'a'; // c1에는 a 의 코드 값인 97이 저장됨.
        char c2 = c1; // c1에 저장되어 있는 값이 c2에 저장된다.
        char c3 = ' '; // c3을 공백으로 초기화.

        int i = c1+1; //98

        c3 = (char) (c1+1); // 덧셈연산의 결과가 int형이므로 char형으로 형변환 해야함.
        c2++;
        c2++;

        System.out.println("i =" +i);  // cout << "i = " << i 와 같은 기능인거 같은데 표현방식이 약간 다르다.
        System.out.println("c2 =" +c2);
        System.out.println("c3 =" +c3);
    }
}
