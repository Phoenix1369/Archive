namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs: Qubit[], bits0: Bool[], bits1: Bool[]) : Int
	{
		body
		{
			let n = Length(qs);
			for (i in 0..n-1)
			{
				let bs = M(qs[i]);
				if ((bs == One) != bits0[i])
				{
					return 1;
				}
			}
			return 0;
		}
	}
}
