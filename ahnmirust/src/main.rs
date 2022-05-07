use rand::distributions::{Distribution, Uniform};
use std::io::Error;
use std::sync::Arc;
use std::sync::atomic::{AtomicBool, Ordering};

fn main() -> Result<(), Error> {
    let term = Arc::new(AtomicBool::new(false));
    signal_hook::flag::register(signal_hook::consts::SIGINT, Arc::clone(&term))?;

    let mut count = 0;
    let mut rng = rand::thread_rng();
    let die = Uniform::from(1..1001);

    while !term.load(Ordering::Relaxed) {
       println!("白って{}色あんねん",die.sample(&mut rng));
       count = count+1; 
    }
    println!("{} 人のアンミカ",count);
    Ok(())
}
