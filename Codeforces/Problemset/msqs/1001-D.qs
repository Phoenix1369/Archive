﻿namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (q: Qubit) : Int
	{
		body
		{
			H(q);
			if(M(q) == Zero)
			{
				return 1;
			}
			return -1;
		}
	}
}
