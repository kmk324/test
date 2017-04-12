/**
 * Created by 민규 on 2017-04-13.
 */
public class FlowEx33
{
    public  static void main (String[] args)
    {
        //이름이 있는 반복문.
        Loop1 : for (int i=2; i <=9; i++)
        {
            for(int j=1; j <=9; j++)
            {
                if (j==5)
                    break Loop1; // 바로 위의 for문이 아니라 loop1이름을 가진 for 문에서 빠져나온다.
                //  break; 비교
                System.out.println(i+"*"+j + "=" +i*j );
            } // end of for j
            System.out.println();
        }
    }
}
