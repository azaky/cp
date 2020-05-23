const
  p:array[0..7] of longint = (1,2,4,8,16,32,64,128);
  k:array[0..7] of longint = (10,9,8,6,5,4,3,2);

var
  tape:string;
  num,i:longint;

begin
  readln(tape);
  repeat
    readln(tape); if tape='___________' then break else num:=0;
	for i:=0 to 7 do if tape[k[i]]='o' then inc(num,p[i]); write(chr(num));
  until false;
end.
