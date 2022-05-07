import java.util.concurrent.atomic.*;
public class ahnmikawhite{
	static AtomicInteger flag = new AtomicInteger(0);
	static int count=0;
	public static void main(String[] args){
		Runtime.getRuntime().addShutdownHook(new Thread(){
			@Override
			public void run(){
				flag.set(1);
				System.out.println(count+" 人のアンミカ");
			}
		});
		while(flag.get()==0){
			System.out.println("白って"+ (int)(Math.random()*(1001-100)+100) +"色あんねん");
			count++;
		}
	}
}
