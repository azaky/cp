const
  two:array[0..8] of integer = (1,2,4,8,16,32,64,128,256);
  bin = '01';

var
  r,c,i,j,p:integer;
  a:array[0..256,0..256] of integer;

procedure encode(r,c,p:integer; cd:string);
  var
    same:boolean;
	i,j:integer;
  
  begin
    same:=true;
	for i:=0 to two[p]-1 do
	  begin
	    for j:=0 to two[p]-1 do
		  if a[i+r,j+c]<>a[r,c] then
			begin
			  same:=false; break;
			end;
		if not same then break;
	  end;
	//writeln(r,' ',c,' ',p,' ',cd,' ',same);
	if same then
	  begin
	    if a[r,c]=1 then writeln('1',cd);
		exit;
	  end;
	dec(p);
	encode(r,c,p,cd+'0');
	encode(r,c+two[p],p,cd+'1');
	encode(r+two[p],c,p,cd+'2');
	encode(r+two[p],c+two[p],p,cd+'3');
  end;

begin
  readln(r,c);
  for i:=1 to r do
    for j:=1 to c do read(a[i,j]);
  p:=0; //n:=0;
  while (two[p]<r) or (two[p]<c) do inc(p);
  encode(1,1,p,'');
  writeln('END');
end.
