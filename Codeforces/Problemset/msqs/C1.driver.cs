using Microsoft.Quantum.Simulation.Core;
using Microsoft.Quantum.Simulation.Simulators;

namespace Solution
{
	class Driver
	{
		const int MAXT = 100;

		static void Main(string[] args)
		{
			int ac = 0;
			int[] cnt = new int[4];
			using (var sim = new QuantumSimulator())
			{
				for (int t = 0; t < MAXT; ++t)
				{
					int que = GetRandomNumber(2);
					int ans = (int)Test.Run(sim, que).Result;
					if (ans == que)
					{
						++cnt[que];
						++ac;
					}
					else
					{
						++cnt[que+2];
					}
				}
			}
			System.Console.WriteLine($"Accept Rate: {1.0*ac/MAXT} " +
				$"00={cnt[0]} 11={cnt[1]}");
		}

		private static readonly System.Random rng = new System.Random();

		public static int GetRandomNumber(int cnt)
		{
			return rng.Next(cnt);
		}
	}
}
