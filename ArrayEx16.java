/**
 * Created by 민규 on 2017-04-27.
 */
class ArrayEx16 {
    public static void main( String [] args)
    {
        System.out.println("매개변수의 개수: "+ args.length);
        for(int i=0; i<args.length; i++)
        {
            System.out.println("args["+ i +"]= \""+args[i] + "\"");
        }
    }
}
// 커맨드라인을 통해 입력받기.