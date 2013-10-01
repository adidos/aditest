package simplemath

import "testing"

func TestSqrt ( t *testing.T) {
	r := Sqrt(16)
	if r != 4{
		t.Errorf("Sqrt(16) failed. Go %d, excepted 4." , r)
	}
}
