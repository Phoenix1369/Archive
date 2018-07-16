namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs: Qubit[]) : Int
	{
		body
		{
			let n = Length(qs);
			mutable cnt = 0;
			for (i in 0..(n-1))
			{
				if (M(qs[i]) == One)
				{
					set cnt = cnt + 1;
				}
			}
			if (cnt == 1)
			{
				return 1;
			}
			return 0;
		}
	}
}
