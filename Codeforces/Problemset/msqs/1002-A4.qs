namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs: Qubit[]) : ()
	{
		body
		{
			let n = Length(qs);
			if (n == 1)
			{
				X(qs[0]);
				return ();
			}

			let k = n / 2;
			Solve(qs[0..k-1]);

			using (qt = Qubit[1])
			{
				let flag = qt[0];
				H(flag);

				for(i in 0..k-1)
				{
					CCSWAP(flag, qs[i], qs[i+k]);
				}
				for(i in 0..k-1)
				{	// Unentangle flag from qs
					CNOT(qs[i], flag);
				}
				Reset(flag);
			}
		}
	}

	operation CCSWAP (c: Qubit, a: Qubit, b: Qubit) : ()
	{
		body
		{
			CCNOT(c, a, b);
			CCNOT(c, b, a);
			CCNOT(c, a, b);
		}
	}
}
