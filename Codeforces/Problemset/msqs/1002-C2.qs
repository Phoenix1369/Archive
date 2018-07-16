namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (q: Qubit) : Int
	{
		body
		{
			let rng = RandomInt(2);
			if (rng == 0)
			{
				if (M(q) == One)
				{
					return 1;
				}
			}
			else
			{
				H(q);
				if (M(q) == One)
				{
					return 0;
				}
			}
			return -1;
		}
	}
}
