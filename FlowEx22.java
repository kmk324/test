/**
 * Created by 민규 on 2017-04-13.
 */
public class FlowEx22 {
    public  static void main (String[] args)
    {
        int [] arr  = {10,20,30,40,50};
        int sum = 0;
        for (int i=0; i<arr.length; i++) //1번
        {
            System.out.printf("%d ",arr[i]);
        }
        System.out.println();
        for (int tmp : arr) // 1번과 동일하다. 향상된 for문임.
        {
            System.out.printf("%d ",tmp);
            sum+= tmp;
        }
        System.out.println();
        System.out.println("sum="+sum);
    }

}
