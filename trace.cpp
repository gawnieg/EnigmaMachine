===Encripting signal===
signal: A
    signal: A after Plugboard
        ..rotating Rotor III to position: 1
        going into Rotor III
        new_rotated_signal: A -> B
        mapped_signal: B -> D
        output_rotated_signal: D -> C
        signal: C after Rotor III
            going into Rotor II
            new_rotated_signal: C -> C
            mapped_signal: C -> D
            output_rotated_signal: D -> D
            signal: D after Rotor II
                going into Rotor I
                new_rotated_signal: D -> D
                mapped_signal: D -> F
                output_rotated_signal: F -> F
                signal: F after Rotor I
                    signal: L after Reflector
                going into Rotor I
                new_rotated_signal: L -> L
                mapped_signal: L -> E
                output_rotated_signal: E -> E
                signal: E after Rotor I
            going into Rotor II
            new_rotated_signal: E -> E
            mapped_signal: E -> Z
            output_rotated_signal: Z -> Z
            signal: Z after Rotor II
        going into Rotor III
        new_rotated_signal: Z -> A
        mapped_signal: A -> T
        output_rotated_signal: T -> S
        signal: S after Rotor III
    signal = S after Plugboard
signal: S
