package simplemath

import "testing"

func TestAdd1 ( t *testing.T) {
	r := Add(11,34)
	if r != 45{
		t.Errorf("Add(11, 34) failed. Go %d, excepted 45." , r)
	}
}
