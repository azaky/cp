var
  n,i,ans,pos,len:integer;
  ch:char;
  line,temp:string;
  sign:array[1..30] of boolean;
  a:array[1..30] of integer;
  flag:array[1..31,0..31,-3000..3000] of boolean;
  can:array[-3000..3000] of boolean;
  res:array[-3000..3000] of string;

procedure cal(pos,open,bef,num:integer; ex:string);
  var
    change:boolean;
    next,i:integer;
    temp,op:string;
    
  begin
    if flag[pos,open,num] then exit;
    flag[pos,open,num]:=true;
    
    //writeln(' ':2*pos,pos,' ',open,' ',num);
    
    inc(pos);
    str(a[pos],temp);
    if sign[pos] then op:='+'
      else op:='-';
    change:=(open mod 2=1);
    if pos<=n then
      begin
        if (change and sign[pos]) or not(change or sign[pos]) then next:=-a[pos]
          else next:=a[pos];
          
        //cal(pos,open,bef,num+next,ex+' '+op+' '+temp);
          
        if not sign[pos] and (pos<n) then cal(pos,open+1,pos,num+next,ex+' '+op+' ('+temp);
        
        if (open>0) and (bef<>pos-1) then cal(pos-1,open-1,0,num,ex+')');
        
        cal(pos,open,bef,num+next,ex+' '+op+' '+temp);
        
        exit;
      end;
    
    for i:=1 to open do ex:=ex+')';
    if not can[num] then
      begin
        inc(ans);
        str(num,temp);
        res[num]:=ex+' = '+temp;
      end;
    can[num]:=true;
  end;

begin
  while not eof do
    begin
      n:=0;
      sign[1]:=true;
      readln(line);
      len:=length(line);
      pos:=0;
      while true do
        begin
          inc(n);
          a[n]:=0;
          repeat
            inc(pos);
            if pos>len then break;
            if (ord(line[pos])<ord('0')) or (ord(line[pos])>ord('9')) then break;
            a[n]:=10*a[n]+ord(line[pos])-ord('0');
          until false;
          if pos>len then break;
          
          while line[pos]=' ' do inc(pos);
          if line[pos]='+' then sign[n+1]:=true
            else sign[n+1]:=false;
          while line[pos+1]=' ' do inc(pos);
        end;
      
      {
      while true do
        begin
          inc(n);
          read(a[n]);
          read(ch);
          if ch<>' ' then break;
          read(ch);
          if ch='+' then sign[n+1]:=true
            else sign[n+1]:=false;
        end;
      }
      fillchar(can,sizeof(can),false);
      fillchar(flag,sizeof(flag),false);
      ans:=0;
      str(a[1],temp);
      cal(1,0,0,a[1],temp);
      //writeln;
      for i:=-3000 to 3000 do
        if can[i] then writeln(res[i]);
      writeln(ans);
      
    end;
end.
