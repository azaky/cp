{
ID: a_zaky01
PROG: clocks
LANG: PASCAL
}

type
  arr = array[1..9] of integer;

var
  i,j,input,total,temptotal,num,int1,int2,int3,int4,int5,int6,int7,int8,int9:integer;
  stat:boolean;
  clock,fix,tempclock,int:arr;
  fin,fout:text;

function check:boolean;
  var
    i:integer;

  begin
    check:=true;
    for i:=1 to 9 do
      if clock[i]<>0 then
        begin
          check:=false;
          break;
        end;
  end;

procedure recall;
  var
    i:integer;

  begin
    for i:=1 to 9 do clock[i]:=tempclock[i];
  end;

procedure move1(k:integer);
  begin
    clock[1]:=(clock[1]+3*k) mod 12;
    clock[2]:=(clock[2]+3*k) mod 12;
    clock[4]:=(clock[4]+3*k) mod 12;
    clock[5]:=(clock[5]+3*k) mod 12;
  end;

procedure move2(k:integer);
  begin
    clock[1]:=(clock[1]+3*k) mod 12;
    clock[2]:=(clock[2]+3*k) mod 12;
    clock[3]:=(clock[3]+3*k) mod 12;
  end;

procedure move3(k:integer);
  begin
    clock[2]:=(clock[2]+3*k) mod 12;
    clock[3]:=(clock[3]+3*k) mod 12;
    clock[5]:=(clock[5]+3*k) mod 12;
    clock[6]:=(clock[6]+3*k) mod 12;
  end;

procedure move4(k:integer);
  begin
    clock[1]:=(clock[1]+3*k) mod 12;
    clock[4]:=(clock[4]+3*k) mod 12;
    clock[7]:=(clock[7]+3*k) mod 12;
  end;

procedure move5(k:integer);
  begin
    clock[2]:=(clock[2]+3*k) mod 12;
    clock[4]:=(clock[4]+3*k) mod 12;
    clock[5]:=(clock[5]+3*k) mod 12;
    clock[6]:=(clock[6]+3*k) mod 12;
    clock[8]:=(clock[8]+3*k) mod 12;
  end;

procedure move6(k:integer);
  begin
    clock[3]:=(clock[3]+3*k) mod 12;
    clock[6]:=(clock[6]+3*k) mod 12;
    clock[9]:=(clock[9]+3*k) mod 12;
  end;

procedure move7(k:integer);
  begin
    clock[4]:=(clock[4]+3*k) mod 12;
    clock[5]:=(clock[5]+3*k) mod 12;
    clock[7]:=(clock[7]+3*k) mod 12;
    clock[8]:=(clock[8]+3*k) mod 12;
  end;

procedure move8(k:integer);

  begin
    clock[7]:=(clock[7]+3*k) mod 12;
    clock[8]:=(clock[8]+3*k) mod 12;
    clock[9]:=(clock[9]+3*k) mod 12;
  end;

procedure move9(k:integer);
  begin
    clock[5]:=(clock[5]+3*k) mod 12;
    clock[6]:=(clock[6]+3*k) mod 12;
    clock[8]:=(clock[8]+3*k) mod 12;
    clock[9]:=(clock[9]+3*k) mod 12;
  end;

begin
  assign(fin,'clocks.in');
  assign(fout,'clocks.out');
  reset(fin);
  rewrite(fout);
  stat:=true;
  for i:=1 to 9 do
    begin
      if i mod 3 = 0 then readln(fin,input)
        else read(fin,input);
      clock[i]:=input mod 12;
      if clock[i]<>0 then stat:=false;
    end;
  if stat then writeln(fout)
    else
      begin
        for i:=1 to 9 do tempclock[i]:=clock[i];
        total:=0;
        for int9:=0 to 3 do
          for int8:=0 to 3 do
            for int7:=0 to 3 do
              for int6:=0 to 3 do
                for int5:=0 to 3 do
                  for int4:=0 to 3 do
                    for int3:=0 to 3 do
                      for int2:=0 to 3 do
                        for int1:=0 to 3 do
                          begin
                            recall;
                            int[1]:=int1;
                            int[2]:=int2;
                            int[3]:=int3;
                            int[4]:=int4;
                            int[5]:=int5;
                            int[6]:=int6;
                            int[7]:=int7;
                            int[8]:=int8;
                            int[9]:=int9;
                            temptotal:=0;
                            for i:=1 to 9 do temptotal:=temptotal+int[i];
                            for i:=1 to 9 do
                              if int[i]>0 then
                                case i of
                                  1:move1(int[i]);
                                  2:move2(int[i]);
                                  3:move3(int[i]);
                                  4:move4(int[i]);
                                  5:move5(int[i]);
                                  6:move6(int[i]);
                                  7:move7(int[i]);
                                  8:move8(int[i]);
                                  9:move9(int[i]);
                                end;
                            if check then
                              if (total=0) or (temptotal<total) then
                                begin
                                  total:=temptotal;
                                  for i:=1 to 9 do fix[i]:=int[i];
                                end;
                          end;
        num:=0;
        for i:=1 to 9 do
          if fix[i]<>0 then
          begin
            num:=num+fix[i];
            if num=total then
              for j:=1 to fix[i] do
                if j=fix[i] then writeln(fout,i)
                  else write(fout,i,' ')
            else for j:=1 to fix[i] do write(fout,i,' ');
          end;
      end;
  close(fin);
  close(fout);
end.
