{
ID: a_zaky01
PROG: cryptcow
LANG: PASCAL
}

const
  msg='Begin the Escape execution at the Break of Dawn';
  elf=23873;

var
  C,O,W,i:integer;
  found:boolean;
  code:string;
  used:array[0..elf] of boolean;
  fin,fout:text;

function matchletter(code:string):boolean;
  var
    i,space:integer;
    c:char;
    count:array['A'..'z'] of integer;

  begin
    matchletter:=true;
    fillchar(count,sizeof(count),0);
    for i:=1 to 47 do
      if msg[i]<>' ' then inc(count[msg[i]]);
    space:=8;
    for i:=1 to length(code) do
      if (code[i]<>'C') and (code[i]<>'O') and (code[i]<>'W') then
        if code[i]=' ' then dec(space)
          else dec(count[code[i]]);
    if space<>0 then exit(false)
      else for c:='A' to 'z' do
        if count[c]<>0 then exit(false);
  end;

function matchsub(sub:string):boolean;
  var
    i,j:integer;
    match:boolean;

  begin
    matchsub:=false;
    for i:=0 to 47-length(sub) do
      begin
        match:=true;
        for j:=1 to length(sub) do
          if msg[i+j]<>sub[j] then
            begin
              match:=false;
              break;
            end;
        if match then exit(true);
      end;
  end;

//www.scalabium.com/faq/dct0136.htm
function elfhash(code:string):boolean;
  var
    i:longint;
    x,temp:int64;

  begin
    temp:=0;
    for i:=1 to length(code) do
      begin
        temp:=(temp shl 4)+ord(code[i]);
        x:=temp and $F0000000;
        if x<>0 then temp:=temp xor (x shr 24);
        temp:=temp and (not x);
      end;
    temp:=temp mod elf;
    if used[temp] then elfhash:=true
      else elfhash:=false;
    used[temp]:=true;
  end;

procedure search(code:string; k:integer);
  var
    pC,pO,pW,iC,iO,iW,len,count:integer;
    temp:array[0..76] of integer;
    next:string;

  begin
    if not found then
      if length(code)=47 then
        if code=msg then
          begin
            writeln(fout,'1 ',k);
            found:=true;
            exit;
          end
        else
      else
        begin
          count:=0;
          len:=length(code);
          for i:=1 to len do
            if (code[i]='C') or (code[i]='O') or (code[i]='W') then
              begin
                inc(count);
                temp[count]:=i;
              end;
          if (code[temp[1]]<>'C') or (code[temp[count]]<>'W') then exit;
          temp[0]:=0;
          inc(count);
          temp[count]:=len+1;
          for i:=1 to count do
            if temp[i]-temp[i-1]<>1 then
              if not matchsub(copy(code,temp[i-1]+1,temp[i]-temp[i-1]-1)) then exit;
          if elfhash(code) then exit;
          for iC:=1 to count-3 do
            if code[temp[iC]]='C' then
              for iO:=iC+1 to count-2 do
                if code[temp[iO]]='O' then
                  for iW:=iO+1 to count-1 do
                    if code[temp[iW]]='W' then
                      begin
                        next:=copy(code,1,temp[iC]-1)+copy(code,temp[iO]+1,temp[iW]-temp[iO]-1)+copy(code,temp[iC]+1,temp[iO]-temp[iC]-1)+copy(code,temp[iW]+1,len-temp[iW]);
                        search(next,k+1);
                      end;
        end;
  end;

begin
  assign(fin,'cryptcow.in');
  assign(fout,'cryptcow.out');
  reset(fin);
  rewrite(fout);
  readln(fin,code);
  C:=0;
  O:=0;
  W:=0;
  for i:=1 to length(code) do
    case code[i] of
      'C':inc(C);
      'O':inc(O);
      'W':inc(W);
    end;
  if (C=O) and (O=W) and (matchletter(code)) then
    begin
      found:=false;
      search(code,0);
      if not found then writeln(fout,'0 0');
    end
  else writeln(fout,'0 0');
  close(fin);
  close(fout);
end.
