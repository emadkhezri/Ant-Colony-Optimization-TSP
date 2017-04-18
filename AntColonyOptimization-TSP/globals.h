//Emad Khezri
//Defination of functions



interior_ptr<unsigned char> GetAsciiString(System::String ^s)
{
    array<unsigned char> ^chars = System::Text::Encoding::ASCII->GetBytes(s);
    return &chars[0];
    // of course you'd want to do some error checking for string length, nulls, etc..
}