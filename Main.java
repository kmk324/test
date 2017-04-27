public class Main {

    public static void main(String[] args) {
        // 자바에서 배열 선언및 생성.
        // 타입 [] 변수이름;  ex) int [] score
        // 변수이름 = new 타입 [길이]; score = new int [4]
        // int[] score = new int [5]

        // 배열의 길이가 0인 배열이 생성 가능하다.

        // 배열이름.length : 배열의 길이를 관리한다. for문에서 유용.

        // int [] score = new int[] {50,60,70,80,90}; 배열의 생성과 초기화를 동시에

        // arrays.toString(배열이름) //[첫번째 요소, 두번째 요소, ...] 배열의 모든 요소를 형식의 문자열로 만들어서 반환.

        // arraycopy() : 어느 배열의 몇번째 요소에서 어느 배열로 몇 번째 요소로 몇 개의 값을 복사할 것인지 지정해줘야한다.
        // ex) System.arraycopy(num, 0 , newNum, 0 , num.length);
        // num [0] 에서 newNum[0]으로 num.leng


        // string 클래스의 주요 메서드
        // char charAt(int index) 문자열에서 해당 위치(index)에 있는 문자를 반환.
        // int length () 문자열의 길이를 반환한다.
        // String substring(int from, int to) 문자열에서 해당 범위(from~to)에 있는 문자열을 반환한다.
        // boolean equals(String str) 문자열의 내용이 같은지 확인한다. 같으면 결과는 true, 다르면 false가 된다.
        // char [] toCharArray() 문자열을 문자배열 (char[])로 변환해서 반환한다.



    }
}
