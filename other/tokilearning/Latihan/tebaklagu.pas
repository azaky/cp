const
  ntone = 24;
  tone:array[1..ntone] of string[2] = ('c.','c#','d.','d#','e.','f.','f#','g.','g#','a.','a#','b.','C.','C#','D.','D#','E.','F.','F#','G.','G#','A.','A#','B.');

type
  song = record
    n:longint;
	arr:array[1..125] of longint;
  end;
  
var
  i,n,k,j,diff:longint;
  s:ansistring;
  map:array[0..1 shl 16] of longint;
  init,a:song;

function createsong(s:ansistring):song;
  var
    i:longint;
  
  begin
    createsong.n:=length(s) div 2;
	fillchar(createsong.arr,sizeof(createsong.arr),255);
	for i:=1 to createsong.n do
	  createsong.arr[i]:=map[256*ord(s[2*i-1])+ord(s[2*i])];
  end;

begin
  for i:=1 to ntone do
    map[256*ord(tone[i][1])+ord(tone[i][2])]:=i;
  readln(s); init:=createsong(s);
  readln(n);
  for k:=1 to n do
    begin
	  readln(s); a:=createsong(s);
	  if a.n<init.n then continue;
	  for i:=0 to a.n-init.n do
	    begin
	      diff:=a.arr[i+1]-init.arr[1];
		  for j:=2 to init.n+1 do
		    begin
		      if j>init.n then
			    begin
			      writeln(k); halt;
			    end;
			  if a.arr[i+j]-init.arr[j]<>diff then break;
		    end;
		end;
	end;
  writeln('#');
end.
