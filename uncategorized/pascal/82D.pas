const
  next:array[1..4,1..2] of longint = ((-1,0),(0,-1),(1,0),(0,1));

var
  n,m,i,j,k,r,c:longint;
  ch:char; found:boolean;
  a:array[0..1001,0..1001] of char;
  app:array['A'..'Z'] of boolean;
  pos:array['A'..'Z',1..2] of longint;
  dir,len:array[1..100001] of longint;
  stop:array[0..1001,0..1001,1..4] of longint;

begin
  readln(n,m);
  for i:=1 to n do
    begin
	  for j:=1 to m do
	    begin
		  read(a[i,j]);
		  if a[i,j] in ['A'..'Z'] then
		    begin
			  app[a[i,j]]:=true;
			  pos[a[i,j]][1]:=i; pos[a[i,j]][2]:=j;
			  a[i,j]:='.';
			end;
		end;
	  readln;
	end;
  //dir
  //1 - north; 2 - west; 3 - south; 4 - east;
  fillchar(stop,sizeof(stop),255);
  //west-east
  for i:=1 to n do
    for j:=1 to m do
	  if a[i,j]='.' then stop[i,j][2]:=stop[i,j-1][2]+1
	    else stop[i,j][2]:=-1;
  //east-west
  for i:=1 to n do
    for j:=m downto 1 do
	  if a[i,j]='.' then stop[i,j][4]:=stop[i,j+1][4]+1
	    else stop[i,j][4]:=-1;
  //north-south
  for i:=1 to m do
    for j:=1 to n do
	  if a[j,i]='.' then stop[j,i][1]:=stop[j-1,i][1]+1
	    else stop[j,i][1]:=-1;
  //south-north
  for i:=1 to m do
    for j:=n downto 1 do
	  if a[j,i]='.' then stop[j,i][3]:=stop[j+1,i][3]+1
	    else stop[j,i][3]:=-1;
  readln(k);
  for i:=1 to k do
    begin
	  read(ch);
	  case ch of
	    'N':dir[i]:=1;
		'W':dir[i]:=2;
		'S':dir[i]:=3;
		'E':dir[i]:=4;
	  end;
	  readln(len[i]);
	end;
  found:=false;
  for ch:='A' to 'Z' do
    begin
	  if not app[ch] then continue;
	  //writeln('node #',ch);
	  r:=pos[ch,1]; c:=pos[ch,2];
	  for i:=1 to k+1 do
	    begin
		  //writeln(r,' ',c);
		  if i>k then
		    begin
			  found:=true;
			  write(ch); break;
			end;
		  if stop[r,c][dir[i]]<len[i] then break;
		  r:=r+next[dir[i],1]*len[i]; c:=c+next[dir[i],2]*len[i];
		end;
	end;
  if found then writeln else writeln('no solution');
end.
